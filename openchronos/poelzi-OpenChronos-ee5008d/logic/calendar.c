#include "project.h"
#ifdef CONFIG_CALENDAR

// driver
#include "display.h"
#include "ports.h"
#include "buzzer.h"
#include "timer.h"

// logic
#include "user.h"
#include "menu.h"
#include "calendar.h"
#include "globalfunctions.h"
#include "date.h"
#include "clock.h"
// Variable declarations
u8 current_agendum	= 0;
u8 current_day 		= 0;
u8 current_alarm	= 0;
u8 menu_L2_old_position = 0;
u8 first_update		= 0;
u8 * days[7]	= {(u8*)"SO", (u8*)"MO", (u8*)"DE", (u8*)"MI", (u8*)"DO", (u8*)"FR", (u8*)"SA"};
u8 * months[12]	= {(u8*)"JA", (u8*)"FE", (u8*)"MR", (u8*)"AP", (u8*)"MA", (u8*)"JN", (u8*)"JL", (u8*)"AG", (u8*)"SP", (u8*)"OK", (u8*)"NV", (u8*)"DE"};
u8 * repeats[4]	= {(u8*)"DLY", (u8*)"WEK", (u8*)"DAT", (u8*)"ONE"};
// struct declarations
calendar sCalendar;
struct global sGlobal_calendar = 
{
	&update_calendar,
	&update_calendar_blink,
	CALLER_CALENDAR
};
// prototypes
void menu_skip_next(u8 line);

void sx_calendar(u8 line)
{
	if (line == LINE1)
	{
		if (++sCalendar.view > VIEW_ALARM2)
			sCalendar.view = VIEW_DATE;
		update_calendar();
		current_alarm = sCalendar.view!=VIEW_DATE?sCalendar.view - 1:5;
	}
	else
	{
		if (sCalendar.view == VIEW_DATE)
		{
			if (++current_agendum >= 5)
				current_agendum = 0;
			update_calendar();
		}
		else
		{
			struct alm * alarm = &sCalendar.days[current_day].alarms[current_alarm];
			if (++(alarm->repeat) > 3)
				(alarm->repeat) = 0;
			if ((alarm->state) == CALENDAR_ALARM_ENABLED)
			{
				sCalendar.repeat_alarms[current_alarm][0] = alarm->repeat;
				sCalendar.repeat_alarms[current_alarm][1] = alarm->hour;
				sCalendar.repeat_alarms[current_alarm][2] = alarm->minute;
			}
			else
			{
				sCalendar.repeat_alarms[current_alarm][0] = 5;
			}
		}
	}
}

void mx_calendar(u8 line)
{
	if (line == LINE1)
	{
		if (sCalendar.view == VIEW_DATE)
		{
			mx_calendar_date();
		}
		else
		{
			mx_calendar_alarm();
		}
	}
	else
	{
		if (sCalendar.view == VIEW_DATE)
		{
			mx_calendar_agendum();
		}
		else
		{
			mx_alarm_repitition();
		}		
	}
}

void nx_calendar(u8 line)
{
	menu_skip_next(LINE1);
	menu_skip_next(LINE2);
	//	menu_L2_position = menu_L2_old_position;
//	ptrMenu_L2->display_function(LINE2, 0);
	sCalendar.view = VIEW_DATE;
}

void dx_calendar(u8 line)
{
	if (line == LINE1)
	{
		if (sCalendar.view == VIEW_DATE)
		{
			return;
		}
		else
		{
			sCalendar.days[current_day].alarms[sCalendar.view-VIEW_ALARM0].state = 1 - sCalendar.days[current_day].alarms[sCalendar.view-VIEW_ALARM0].state;
			check_alarms();
		}
	}
	else if (line == LINE2)
	{
		if (sCalendar.view != VIEW_DATE)
		{
			sCalendar.days[current_day].agenda[current_agendum].state==CALENDAR_TIMER_ON?stop_calendar_agendum():start_calendar_agendum();
		}
		else
		{
			if (sCalendar.days[current_day].agenda[current_agendum].state)
			{
				stop_calendar_agendum();
			}
			else
			{
				start_calendar_agendum();
			}
		}
	}
}

void mx_calendar_agendum(void)
{
	u16 pos = sCalendar.days[current_day].agenda[current_agendum].pos;
	u8 size = sCalendar.days[current_day].agenda[current_agendum].size;
	stop_calendar_agendum();
	clear_display_all();
	u8 select = 0;
	while (!numexit)
	{
		pos = select<2?0:(select-1)>(size-5)?size-5:select-2;
		set_alphanum_value(sCalendar.days[current_day].agenda[current_agendum].content, &sCalendar.days[current_day].agenda[current_agendum].charnum, select, &pos, &sGlobal_calendar, LINE2);
		if (++select >= size)	select = 0;
	}
	sCalendar.days[current_day].agenda[current_agendum].pos = 0;
	numexit = 0;
	// Clear button presses
	button.all_flags = 0;
}
void mx_calendar_alarm(void)
{
	u8 select = 0;
	s32 hours;
	s32 minutes;
	u8 * str;
	
	// Clear display
	clear_display_all();

	// Keep global values in case new values are discarded
	hours 		= sCalendar.days[current_day].alarms[current_alarm].hour;
	minutes 	= sCalendar.days[current_day].alarms[current_alarm].minute;

	// Display HH:MM (LINE1) 
	str = itoa(hours, 2, 0);
	display_chars(LCD_SEG_L1_3_2, str, SEG_ON);
	display_symbol(LCD_SEG_L1_COL, SEG_ON);
	
	str = itoa(minutes, 2, 0);
	display_chars(LCD_SEG_L1_1_0, str, SEG_ON);

	while(1)
	{
		// Idle timeout: exit without saving
		if (sys.flag.idle_timeout) break;

		// STAR (short): save, then exit
		if (button.flag.star)
		{
			// Store local variables in global alarm time
			sCalendar.days[current_day].alarms[current_alarm].hour = hours;
			sCalendar.days[current_day].alarms[current_alarm].minute = minutes;
			// Set display update flag
			display.flag.line1_full_update = 1;
			break;
		}

		select==0?set_value(&hours, 2, 0, 0, 23, SETVALUE_ROLLOVER_VALUE + SETVALUE_DISPLAY_VALUE + SETVALUE_NEXT_VALUE, LCD_SEG_L1_3_2, display_value1):
			set_value(&minutes, 2, 0, 0, 59, SETVALUE_ROLLOVER_VALUE + SETVALUE_DISPLAY_VALUE + SETVALUE_NEXT_VALUE, LCD_SEG_L1_3_2, display_value1);
		select = 1-select;
	}
	// Clear button flag
	button.all_flags = 0;
}
void mx_calendar_date(void)
{
	u8 select;
	s32 day;
	s32 month;
	s32 year;
	s16 max_days = 30;
	u8 * str;
			
	// Clear display
	clear_display_all();
			
	// Convert global to local variables
	day 	= current_day;
	month 	= sCalendar.month;
	year 	= sCalendar.year;
		
	// Init value index
	select = 0;	
	
	// Init display
	// LINE1: YYYY (will be drawn by set_value)
	// LINE2: MM  DD
	
	str = itoa(day, 2, 1);
	display_chars(LCD_SEG_L2_1_0, str, SEG_ON);

	str = itoa(month, 2, 1);
	display_chars(LCD_SEG_L2_5_4, str, SEG_ON);

	// Loop values until all are set or user breaks	set
	while(1) 
	{
		// Idle timeout: exit without saving 
		if (sys.flag.idle_timeout) break;

		// Button STAR (short): save, then exit 
		if (button.flag.star) 
		{
			// Copy local variables to global variables
			current_day = day;
			sCalendar.month = month;
			sCalendar.year = year;
			
			// Full display update is done when returning from function
			break;
		}

		switch (select)
		{
			case 0:		// Set year
						set_value(&year, 4, 0, 2008, 2100, SETVALUE_DISPLAY_VALUE + SETVALUE_NEXT_VALUE, LCD_SEG_L1_3_0, display_value1);
						select = 1;
						break;
			case 1:		// Set month
						set_value(&month, 2, 1, 1, 12, SETVALUE_ROLLOVER_VALUE + SETVALUE_DISPLAY_VALUE + SETVALUE_NEXT_VALUE, LCD_SEG_L2_5_4, display_value1);
						select = 2;
						break;
			case 2:		// Set day
						set_value(&day, 2, 1, 1, max_days, SETVALUE_ROLLOVER_VALUE + SETVALUE_DISPLAY_VALUE + SETVALUE_NEXT_VALUE, LCD_SEG_L2_1_0, display_value1);
						select = 0;
						break;
		}
		
		// Check if day is still valid, if not clamp to last day of current month
		max_days = get_numberOfDays(month, year);
		if (day > max_days) day = max_days;
	}
	current_day = day;
	// Clear button flag
	button.all_flags = 0;
}
void mx_alarm_repitition(void)
{
	set_var(&sCalendar.days[current_day].alarms[current_alarm].repeat, repeats, 0, 3, LCD_SEG_L2_4_3);
}
void display_calendar(u8 line, u8 update)
{
	if (update == DISPLAY_LINE_UPDATE_PARTIAL || update == DISPLAY_LINE_UPDATE_FULL)
	{
		check_alarm_symbol();
		if (line == LINE1)
		{
			if (sCalendar.view == VIEW_DATE)
			{
				display_chars(LCD_SEG_L1_3_2, days[get_Day_Of_Week(current_day, sDate.month, sDate.year)], SEG_ON_BLINK_OFF);
				display_chars(LCD_SEG_L1_1_0, itoa(sDate.day, 2, 0), SEG_ON_BLINK_OFF);
				//display_symbol(LCD_SEG_L1_DP1, SEG_ON_BLINK_OFF);
			}
			else
			{
				display_chars(LCD_SEG_L1_3_2, itoa(sCalendar.days[current_day].alarms[sCalendar.view-VIEW_ALARM0].hour, 2, 0), SEG_ON_BLINK_OFF);
				display_chars(LCD_SEG_L1_1_0, itoa(sCalendar.days[current_day].alarms[sCalendar.view-VIEW_ALARM0].minute, 2, 0), SEG_ON_BLINK_OFF);
				check_arrow_state();
			}
		}
		else
		{
			if (sCalendar.view == VIEW_DATE)
			{
				display_chars(LCD_SEG_L2_4_0, sCalendar.days[current_day].agenda[current_agendum].content, SEG_ON_BLINK_OFF);
			}
			else
			{
				u8 dofw = get_Day_Of_Week(current_day, sDate.month, sDate.year);
				display_chars(LCD_SEG_L2_1_0, days[dofw], SEG_ON_BLINK_OFF);
				display_chars(LCD_SEG_L2_4_2, repeats[sCalendar.days[current_day].alarms[current_alarm].repeat], SEG_ON_BLINK_OFF);
				display_symbol(LCD_SEG_L2_DP, SEG_ON_BLINK_OFF);
			}
		}
	}
	else
	{
		check_alarm_symbol();
		if (line == LINE1)
		{
			display_symbol(LCD_SEG_L1_DP0, SEG_OFF_BLINK_OFF);
			display_symbol(LCD_SEG_L1_DP1, SEG_OFF_BLINK_OFF);
			display_symbol(LCD_SYMB_ARROW_UP, SEG_OFF_BLINK_OFF);
			display_symbol(LCD_SYMB_ARROW_DOWN, SEG_OFF_BLINK_OFF);
		}
		else
		{
			display_symbol(LCD_SEG_L2_DP, SEG_OFF_BLINK_OFF);
		}
	}
	first_update = 0;
}

u8 update_calendar(void)
{
	display_calendar(LINE1, DISPLAY_LINE_UPDATE_FULL);
	display_calendar(LINE2, DISPLAY_LINE_UPDATE_FULL);
	return 1;
}

u8 is_calendar(void)
{
	return (ptrMenu_L1 == &menu_L1_Calendar || ptrMenu_L2 == &menu_L1_Calendar);
}

void update_calendar_blink(u8 digit, u8 line)
{
	
}
void start_calendar_agendum(void)
{
	sCalendar.days[current_day].agenda[current_agendum].state = CALENDAR_TIMER_ON;
	sCalendar.days[current_day].agenda[current_agendum].pos = 0;
	display_symbol(LCD_ICON_RECORD, SEG_ON_BLINK_OFF);

}
void stop_calendar_agendum(void)
{
	sCalendar.days[current_day].agenda[current_agendum].state = CALENDAR_TIMER_OFF;
	sCalendar.days[current_day].agenda[current_agendum].pos = 0;
	display_symbol(LCD_ICON_RECORD, SEG_OFF_BLINK_OFF);
}
void tick_calendar_agendum(void)
{
	u16 * pos = &sCalendar.days[current_day].agenda[current_agendum].pos;
	if(sCalendar.days[current_day].agenda[current_agendum].state == CALENDAR_TIMER_ON){
		(*pos)++;
		if(*pos > sCalendar.days[current_day].agenda[current_agendum].size-4)
		{
			*pos = 0;
		}
		update_calendar();
	}

}
void reset_calendar_agendum(u8 num)
{
	struct agendum * agend = &sCalendar.days[current_day].agenda[current_agendum];
	u8 i = 0;
	for(;i < agend->size;i++)
	{
		agend->content[i] = itoa(i, 1, 0);
	}
	agend->size = AGENDUM_DEFAULT_SIZE;
}
void check_alarms(void)
{
	check_alarm_symbol();
	check_arrow_state();
	u8 i;
	for(i = 0;i<3;i++)
	{
#ifdef CONFIG_SCHOOL_ALARM
		check_school_alarm(&sCalendar.days[sDate.day].alarms[i].minute, &sCalendar.days[sDate.day].alarms[i].hour, &sCalendar.days[sDate.day].alarms[i].state);
#endif
		if (sCalendar.days[sDate.day].alarms[i].state != CALENDAR_ALARM_DISABLED)
		{
			if (sTime.hour == sCalendar.days[sDate.day].alarms[i].hour)
			{
				if (sTime.minute == sCalendar.days[sDate.day].alarms[i].minute)
				{
					sCalendar.days[sDate.day].alarms[i].state = CALENDAR_ALARM_ON;
					sCalendar.days[sDate.day].buzzer = 1;
				}
			}
		}
	}
}
void stop_calendar_alarm(void)
{
	u8 i;
	for(i = 0;i<3;i++)
	{
		if(sCalendar.days[sDate.day].alarms[i].state == CALENDAR_ALARM_ON)
		{
			sCalendar.days[sDate.day].alarms[i].state = CALENDAR_ALARM_ENABLED;
			stop_buzzer();
		}
	}	
}
void check_alarm_symbol(void)
{
	u8 state = SEG_OFF_BLINK_OFF;
	if (is_calendar())
	{
		state = SEG_ON_BLINK_ON;
	}
	else if (sCalendar.days[current_day].alarms[0].state || sCalendar.days[current_day].alarms[1].state || sCalendar.days[current_day].alarms[2].state)
	{
		state = SEG_ON_BLINK_OFF;
	}
	display_symbol(LCD_ICON_ALARM, state);
}
void check_arrow_state(void)
{
		display_symbol(LCD_SYMB_ARROW_DOWN, SEG_OFF_BLINK_OFF);
		display_symbol(LCD_SYMB_ARROW_UP, SEG_OFF_BLINK_OFF);
		if (sCalendar.view == VIEW_DATE)
			return;
		u8 arrow = LCD_SYMB_ARROW_DOWN;
		u8 mode = SEG_OFF_BLINK_OFF;
		u8 state = sCalendar.days[current_day].alarms[current_alarm].state;
		if (state == CALENDAR_ALARM_ENABLED)
		{
			arrow = LCD_SYMB_ARROW_UP;
			mode = SEG_ON_BLINK_OFF;
		}
		else if (state == CALENDAR_ALARM_DISABLED)
		{
			arrow = LCD_SYMB_ARROW_DOWN;
			mode = SEG_ON_BLINK_OFF;
		}
		else if (state == CALENDAR_ALARM_ON)
		{
			arrow = LCD_SYMB_ARROW_UP;
			mode = SEG_ON_BLINK_ON;
		}
		display_symbol(arrow, mode);
}
#ifdef CONFIG_SCHOOL_ALARM
void check_school_alarm(u8 * minute, u8 * hour, u8 * state)
{
	u8 day = get_Day_Of_Week(sDate.day, sDate.month, sDate.year);
	if(*minute == 25 && (*hour == 7 || *hour == 6) && (day == 2 || day == 3 || day == 5))
	{
		*state = CALENDAR_ALARM_ENABLED;
		*hour = 6;
	}
	else if(*minute == 25 && (*hour == 7 || *hour == 6) && day == 4)
	{
		*state = CALENDAR_ALARM_ENABLED;
		*hour = 7;
	}
	else if(*minute == 25 && (*hour == 7 || *hour == 6) && (day == 0 || day == 6))
	{
		*state = CALENDAR_ALARM_DISABLED;
	}
}
#endif
#endif
