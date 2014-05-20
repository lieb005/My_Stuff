#include "project.h"
#ifdef CONFIG_SCHEDULE
#include "display.h"
#include "ports.h"
#include "buzzer.h"
#include "timer.h"
#include "clock.h"
#include "date.h"


// logic
#include "user.h"

#include "menu.h"
#include "schedule.h"

struct schedule sSchedule;

void mx_schedule(u8 line)
{
	sSchedule.state = sSchedule.state == SCHEDULE_DISABLED?SCHEDULE_ENABLED:SCHEDULE_DISABLED;
	update_schedule(line);
}

void sx_schedule(u8 line)
{
	if(button.flag.down)
	{
		sSchedule.currentlyShown = sSchedule.currentlyShown == TIME?PERIOD:TIME;
		update_schedule(line);
	}
}

void display_schedule(u8 line, u8 update)
{
	update_schedule(line);
}

u8 update_schedule()
{
	update_schedule_time();
	clear_line(LINE2);
	if(sSchedule.state == SCHEDULE_ENABLED)
	{
		if(sSchedule.currentlyShown == PERIOD)
		{
			display_chars(LCD_SEG_L2_4_0, sSchedule.period, SEG_ON);
		}
		else if(sSchedule.currentlyShown == TIME)
		{
			display_chars(LCD_SEG_L2_3_0, itoa(sSchedule.end, 4, 0), SEG_ON);
			display_symbol(LCD_SEG_L2_COL0, SEG_ON);
		}
	}
	else if (sSchedule.state == SCHEDULE_DISABLED)
	{
		display_chars(LCD_SEG_L2_4_0, sSchedule.period, SEG_ON);
	}
	/*else if (sSchedule.state == SCHEDULE_NONE)
	{
		if (is_schedule())
		{
			menu_skip_next(LINE2);
		}
	}*/
	return 1;
}
void update_schedule_time()
{
	u8 * period = (u8*)"ERROR";
	u16 end = 0000;
	u16 time = (sTime.hour*100) + sTime.minute;
	sSchedule.dayOfWeek = get_Day_Of_Week(sDate.day, sDate.month, sDate.year);
	if(sSchedule.state == SCHEDULE_ENABLED || sSchedule.state == SCHEDULE_NONE)
	{
		switch(sSchedule.dayOfWeek)
		{
			// Weekend
			case 0:
			case 6:
				sSchedule.state = SCHEDULE_NONE;
				break;
			// Monday
			case 1:
				switch(time)
				{
					case 0 ... 724:
						period = (u8*)"START";
						end = 725;
						break;
					case 725 ... 814:
						period = (u8*)"PER 1";
						end = 815;
						break;
					case 815 ... 909:
						period = (u8*)"PER 2";
						end = 910;
						break;
					case 910 ... 1004:
						period = (u8*)"PER 3";
						end = 1005;
						break;
					case 1005 ... 1019:
						period = (u8*)"BREAK";
						end = 1020;
						break;
					case 1020 ... 1114:
						period = (u8*)"PER 4";
						end = 1115;
						break;
					case 1115 ... 1209:
						period = (u8*)"PER 5";
						end = 1210;
						break;
					case 1210 ... 1239:
						period = (u8*)"LUNCH";
						end = 1240;
						break;
					case 1240 ... 1334:
						period = (u8*)"PER 6";
						end = 1335;
						break;
					case 1335 ... 1434:
						period = (u8*)"S PER";
						end = 1435;
						break;
					case 1435 ... 1519:
						period = (u8*)"PER 7";
						end = 1520;
						break;
					case 1520 ... 1600:
						period = (u8*)"END  ";
						break;
					default:
						sSchedule.state = SCHEDULE_NONE;
						break;
				}
				break;
			// Thursday
			case 4:
				switch(time)
				{
					case 0 ... 824:
						period = (u8*)"START";
						end = 825;
						break;
					case 825 ... 914:
						period = (u8*)"PER 1";
						end = 915;
						break;
					case 915 ... 1009:
						period = (u8*)"PER 2";
						end = 1010;
						break;
					case 1010 ... 1019:
						period = (u8*)"BREAK";
						end = 1020;
						break;
					case 1020 ... 1114:
						period = (u8*)"PER 3";
						end = 1115;
						break;
					case 1115 ... 1214:
						period = (u8*)"PER 4";
						end = 1215;
						break;
					case 1215 ... 1244:
						period = (u8*)"LUNCH";
						end = 1245;
						break;
					case 1245 ... 1339:
						period = (u8*)"PER 5";
						end = 1340;
						break;
					case 1340 ... 1434:
						period = (u8*)"PER 6";
						end = 1435;
						break;
					case 1435 ... 1519:
						period = (u8*)"PER 7";
						end = 1520;
						break;
					case 1520 ... 1600:
						period = (u8*)"END  ";
						break;
					default:
						sSchedule.state = SCHEDULE_NONE;
						break;
				}
				break;
			// Tuesday, Wednesday, Friday
			case 2:
			case 3:
			case 5:
				switch(time)
				{
					case 0 ... 724:
						period = (u8*)"START";
						end = 725;
						break;
					case 725 ... 824:
						period = (u8*)"PER 1";
						end = 825;
						break;
					case 825 ... 929:
						period = (u8*)"PER 2";
						end = 930;
						break;
					case 930 ... 939:
						period = (u8*)"BREAK";
						end = 940;
						break;
					case 940 ... 1044:
						period = (u8*)"PER 3";
						end = 1045;
						break;
					case 1045 ... 1154:
						period = (u8*)"PER 4";
						end = 1155;
						break;
					case 1155 ... 1224:
						period = (u8*)"LUNCH";
						end = 1225;
						break;
					case 1225 ... 1329:
						period = (u8*)"PER 5";
						end = 1330;
						break;
					case 1330 ... 1434:
						period = (u8*)"PER 6";
						end = 1435;
						break;
					case 1435 ... 1529:
						period = (u8*)"PER 7";
						end = 1530;
						break;
					case 1530 ... 1600:
						period = (u8*)"END  ";
						break;
					default:
						sSchedule.state = SCHEDULE_NONE;
						break;
				}
				break;
		}
	}
	else
	{
		period = (u8*)"OFF  ";
	}
	sSchedule.end = end;
	sSchedule.period = period;
}
u8 is_schedule(void)
{
	return(ptrMenu_L2 == &menu_L2_Schedule);
}
#endif

