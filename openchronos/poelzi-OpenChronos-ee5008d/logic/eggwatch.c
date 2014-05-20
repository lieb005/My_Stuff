// *************************************************************************************************
//
//	Copyright (C) 2009 Texas Instruments Incorporated - http://www.ti.com/ 
//	 
//	 
//	  Redistribution and use in source and binary forms, with or without 
//	  modification, are permitted provided that the following conditions 
//	  are met:
//	
//	    Redistributions of source code must retain the above copyright 
//	    notice, this list of conditions and the following disclaimer.
//	 
//	    Redistributions in binary form must reproduce the above copyright
//	    notice, this list of conditions and the following disclaimer in the 
//	    documentation and/or other materials provided with the   
//	    distribution.
//	 
//	    Neither the name of Texas Instruments Incorporated nor the names of
//	    its contributors may be used to endorse or promote products derived
//	    from this software without specific prior written permission.
//	
//	  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
//	  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
//	  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
//	  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
//	  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
//	  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
//	  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
//	  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
//	  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
//	  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
//	  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// *************************************************************************************************
// eggwatch feature
// *************************************************************************************************

// *************************************************************************************************
// Include section

// system
#include "project.h"	//gibbons: bit of a hack: forces next ifdef statement to work
#ifdef CONFIG_EGGWATCH

#include <string.h>

// driver
#include "ports.h"
#include "display.h"
#include "timer.h"
#include "buzzer.h"
#include "user.h"

// logic
#include "menu.h"
#include "eggwatch.h"


// *************************************************************************************************
// Prototypes section
void init_eggwatch(void);
void start_eggwatch(void);
void stop_eggwatch(void);
void stop_eggwatch_alarm(void);
void set_eggwatch_to_defaults(void);
void set_eggwatch(void);
void eggwatch_tick(void);
void mx_eggwatch(u8 line);
void sx_eggwatch(u8 line);
void display_eggwatch(u8 line, u8 update);
u8 eggwatch_visible(void);

// *************************************************************************************************
// Defines section


// *************************************************************************************************
// Global Variable section
struct eggwatch sEggwatch;


// *************************************************************************************************
// Extern section
extern void menu_skip_next(line_t line); // in ezchronos.c


// *************************************************************************************************
// @fn          init_eggwatch
// @brief       Initialize eggwatch; intended to be called once, on firmware restart
// @param       none
// @return      none
// *************************************************************************************************
void init_eggwatch()
{
sEggwatch.state = EGGWATCH_STOP;
sEggwatch.duration = EGGWATCH_ALARM_DURATION;
sEggwatch.direction = EGGWATCH_COUNT_UP;
sEggwatch.paused = EGGWATCH_SET;

// Set eggwatch default to 0 minutes
sEggwatch.default_hours = 0;
sEggwatch.default_minutes = 0;
sEggwatch.default_seconds = 0;

set_eggwatch_to_defaults();
}


// *************************************************************************************************
// @fn          start_eggwatch
// @brief       Sets eggwatch state to on, draws eggwatch icon blinking
// @param       none
// @return      none
// *************************************************************************************************
void start_eggwatch(void)
{
	// Set eggwatch run flag
	sEggwatch.state = EGGWATCH_RUN;
	if (sEggwatch.paused == EGGWATCH_SET)
	{
		if (sEggwatch.hours == 0 && sEggwatch.minutes == 0 && sEggwatch.seconds == 0)
		{
			sEggwatch.direction = EGGWATCH_COUNT_UP;
		}
		else
		{
			sEggwatch.direction = EGGWATCH_COUNT_DOWN;
		}
	}
	

	// Set eggwatch icon (doesn't exist so I wont untill I'll use stopwatch for now)
	display_symbol(LCD_ICON_STOPWATCH, SEG_ON_BLINK_ON);
}


// *************************************************************************************************
// @fn          stop_eggwatch
// @brief       Sets eggwatch state to off, but doesn't reset eggwatch count. 
//		  Also draws eggwatch icon (solid on, no blink)
// @param       none
// @return      none
// *************************************************************************************************
void stop_eggwatch(void)
{	
	// Clear eggwatch run flag
	sEggwatch.state = EGGWATCH_STOP;
	sEggwatch.paused = EGGWATCH_PAUSED;
	
	// Clear eggwatch icon (doesn't exist so I'll use stopwatch for now)
	display_symbol(LCD_ICON_STOPWATCH, SEG_ON_BLINK_OFF); // Assumes the eggwatch menu is active
}


// *************************************************************************************************
// @fn          stop_eggwatch_alarm
// @brief       Puts eggwatch in STOP mode, halts alarm mode and buzzing if active, updates eggwatch
//			symbol. Safe to call, even if eggwatch menu not active.
// @param       none
// @return      none
// *************************************************************************************************
void stop_eggwatch_alarm(void)
{
	sEggwatch.state = EGGWATCH_STOP;
	sEggwatch.duration = EGGWATCH_ALARM_DURATION;
	if (eggwatch_visible()) {
		display_symbol(LCD_ICON_STOPWATCH, SEG_ON_BLINK_OFF);
	}
	else {
		display_symbol(LCD_ICON_STOPWATCH, SEG_OFF_BLINK_OFF);
	}
	stop_buzzer(); // FIXME: needs to play friendly with other buzzer-using modules (e.g. alarm)
}


// *************************************************************************************************
// @fn          set_eggwatch_to_defaults
// @brief       Clears eggwatch counter; DOES NOT set state to eggwatch_STOP! (This way, this
//			function can be called without stopping the alarm.)
// @param       none
// @return      none
// *************************************************************************************************
void set_eggwatch_to_defaults(void)
{
	// Reset eggwatch counts to default (aka last used) values
	sEggwatch.hours = sEggwatch.default_hours;
	sEggwatch.minutes = sEggwatch.default_minutes;
	sEggwatch.seconds = sEggwatch.default_seconds;
	
	if (eggwatch_visible()) {
		display.flag.line2_full_update = 1; // gibbons: this is hardcoded to line 2; change?
	}
}


// *************************************************************************************************
// @fn          set_eggwatch
// @brief       Set's the eggwatch. (Almost entirely copied from the alarm section
// @param       none
// @return      none
// *************************************************************************************************
extern void set_eggwatch(void){
	u8 select;
	s32 hours; // must be s32 to work properly with set_value(...)
	s32 minutes;
	s32 seconds;
	u8 * str;
	sEggwatch.paused = EGGWATCH_SET;
	
	// Store hours, minutes, and seconds in local variables
	hours   = sEggwatch.hours;
	minutes = sEggwatch.minutes;
	seconds = sEggwatch.seconds;
	
	// Display HH:MM:SS (LINE2)
	str = itoa(hours, 2, 0);
	display_chars(LCD_SEG_L2_5_4, str, SEG_ON);
	str = itoa(minutes, 2, 0);
	display_chars(LCD_SEG_L2_3_2, str, SEG_ON);
	str = itoa(seconds, 2, 0);
	display_chars(LCD_SEG_L2_1_0, str, SEG_ON);

	// Init value index
	select = 0;

	// Loop values until all are set or user breaks set
	while(1) 
	{
		// Idle timeout: exit without saving 
		if (sys.flag.idle_timeout) break;
		
		// M2 (short): save, then exit 
		if (button.flag.num) 
		{
			//if ((hours == 0) && (minutes == 0) && (seconds == 0)) { //prevent zero time
				//seconds = 1;
			//}
			// Store local variables in global eggwatch default and counters
			sEggwatch.hours = sEggwatch.default_hours = hours;
			sEggwatch.minutes = sEggwatch.default_minutes = minutes;
			sEggwatch.seconds = sEggwatch.default_seconds = seconds;
			break;
		}

		switch (select)
		{
			case 0: // Set hours
			set_value(&hours, 2, 0, 0, 19, SETVALUE_ROLLOVER_VALUE + SETVALUE_DISPLAY_VALUE + SETVALUE_NEXT_VALUE, LCD_SEG_L2_5_4, display_value1);
			select = 1;
			break;

			case 1:	// Set minutes
				//var   digits blank min/max val       ?                            ?                          ?          seg array   which Fn to call to display              
			set_value(&minutes, 2,    0,   0,  99,    SETVALUE_ROLLOVER_VALUE + SETVALUE_DISPLAY_VALUE + SETVALUE_NEXT_VALUE, LCD_SEG_L2_3_2, display_value1);
			select = 2;
			break;
					
			case 2:	// Set seconds
			set_value(&seconds, 2, 0, 0, 99, SETVALUE_ROLLOVER_VALUE + SETVALUE_DISPLAY_VALUE + SETVALUE_NEXT_VALUE, LCD_SEG_L2_1_0, display_value1);
			select = 0;
			break;
		}
	}
	if (sEggwatch.hours == 0 && sEggwatch.minutes == 0  && sEggwatch.seconds == 0)
		sEggwatch.direction = EGGWATCH_COUNT_UP;
	else
		sEggwatch.direction = EGGWATCH_COUNT_DOWN;
	// Clear button flag
	button.all_flags = 0;
}


// *************************************************************************************************
// @fn          eggwatch_tick
// @brief       To be called every second; decreases eggwatch counter and sets display update flag.
// @param       none
// @return      none
// *************************************************************************************************
void eggwatch_tick(void) //gibbons: This function could benefit from an alarm queue...
{
	if (sEggwatch.state != EGGWATCH_RUN) return;

	//sEggwatch.drawFlag == 1 --> seconds changed
	//sEggwatch.drawFlag == 2 --> minutes also changed
	//sEggwatch.drawFlag == 3 --> hours also changed

	sEggwatch.drawFlag = 1;
	display.flag.update_eggwatch = 1;
	if (sEggwatch.direction == EGGWATCH_COUNT_DOWN)
	{
		// gibbons: Is it possible to merge the if and else if blocks into one?
// 		if ((sEggwatch.hours == 0) && (sEggwatch.minutes == 0) && (sEggwatch.seconds == 1))
// 		{
// 			// Die Zeit ist um! Time's up!
// 			sEggwatch.state = EGGWATCH_ALARM;
// 			set_eggwatch_to_defaults(); // Set values to defaults, so user can see what time duration just timed out
// 		}
		if (sEggwatch.seconds-- == 0) // NOTE: intentionally sEggwatch.seconds--, and not --sEggwatch.seconds
		{
			if ((sEggwatch.hours == 0) && (sEggwatch.minutes == 0))
			{
				// Die Zeit ist um!
				sEggwatch.state = EGGWATCH_ALARM;
				set_eggwatch_to_defaults(); // Set values to defaults, so user can see what time duration just timed out
				return;
			}
			sEggwatch.seconds = 59;
			sEggwatch.drawFlag++;
			// Subtract a minute from the remaining time
			if (sEggwatch.minutes-- == 0)
			{
				sEggwatch.minutes = 59;
				sEggwatch.drawFlag++;
				// Subtract an hour from the remaining time
				sEggwatch.hours--;
			}
		}
	}
	else
	{
		if (++sEggwatch.seconds == 60)
		{
			sEggwatch.seconds = 0;
			if (++sEggwatch.minutes == 60)
			{
				sEggwatch.minutes = 0;
				++sEggwatch.hours;
			}
		}
	}
}

// *************************************************************************************************
// @fn          mx_eggwatch
// @brief       eggwatch set routine. Mx stops eggwatch and resets count.
// @param       u8 line	LINE2
// @return      none
// *************************************************************************************************
void mx_eggwatch(u8 line)
{
	sEggwatch.update_display = 1;
	// Stop eggwatch
	stop_eggwatch();
	
	// Reset eggwatch count to default values
	set_eggwatch_to_defaults();
	
	// Set eggwatch
	set_eggwatch();
			
	// Display eggwatch time
	display_eggwatch(line, DISPLAY_LINE_UPDATE_FULL);
}


// *************************************************************************************************
// @fn          sx_eggwatch
// @brief       eggwatch direct function. S2 starts/stops eggwatch, but does not reset count.
// @param       u8 line	LINE2
// @return      none
// *************************************************************************************************
void sx_eggwatch(u8 line)
{
	sEggwatch.update_display = 1;
	if (sEggwatch.state == EGGWATCH_STOP)
	{
		// (Re)start eggwatch
		start_eggwatch();
	}
	else 
	{
		// Stop eggwatch 
		stop_eggwatch();
	}
}




// *************************************************************************************************
// @fn          dx_eggwatch
// @brief       eggwatch direct function. S2 long resets eggwatch or does Lap
// @param       u8 line	LINE2
// @return      none
// *************************************************************************************************
void dx_eggwatch(u8 line)
{
	if (sEggwatch.state == EGGWATCH_STOP)
	{
		sEggwatch.default_hours = 0;
		sEggwatch.default_minutes = 0;
		sEggwatch.default_seconds = 0;
		sEggwatch.direction = EGGWATCH_COUNT_UP;
	}
	else if (sEggwatch.state == EGGWATCH_RUN)
	{
		sEggwatch.update_display = sEggwatch.update_display?0:1;
		sEggwatch.old_hours = sEggwatch.hours;
		sEggwatch.old_minutes = sEggwatch.minutes;
		sEggwatch.old_seconds = sEggwatch.seconds;
	}
}


// *************************************************************************************************
// @fn          display_eggwatch
// @brief       eggwatch user routine.
// @param       u8 line		LINE2
//		u8 update	DISPLAY_LINE_UPDATE_PARTIAL, DISPLAY_LINE_UPDATE_FULL
// @return      none
// *************************************************************************************************
void display_eggwatch(u8 line, u8 update)
{
	if (sEggwatch.update_display)
	{
		u8 * str;
		
		u8 minutes = sEggwatch.update_display?sEggwatch.minutes:sEggwatch.old_minutes;
		u8 seconds = sEggwatch.update_display?sEggwatch.seconds:sEggwatch.old_seconds;
		u8 hours = sEggwatch.update_display?sEggwatch.hours:sEggwatch.old_hours;
		
		// Partial line update only
		if (update == DISPLAY_LINE_UPDATE_PARTIAL)
		{
			// Check draw flag to minimize workload
			switch(sEggwatch.drawFlag) 
			{
				case 3: // Hours changed
			str = itoa(hours, 2, 0);
			display_chars(LCD_SEG_L2_5_4, str, SEG_ON);
				case 2: // Minutes changed
			str = itoa(minutes, 2, 0);
			display_chars(LCD_SEG_L2_3_2, str, SEG_ON);
				case 1: // Seconds changed
			str = itoa(seconds, 2, 0);
			display_chars(LCD_SEG_L2_1_0, str, SEG_ON);
			}
			sEggwatch.drawFlag = 0; // Clear draw flag
		}
		// Redraw whole line
		else if (update == DISPLAY_LINE_UPDATE_FULL)	
		{
			// Display HH:MM:SS		
			str = itoa(hours, 2, 0);
			display_chars(LCD_SEG_L2_5_4, str, SEG_ON);
			str = itoa(minutes, 2, 0);
			display_chars(LCD_SEG_L2_3_2, str, SEG_ON);
			str = itoa(seconds, 2, 0);
			display_chars(LCD_SEG_L2_1_0, str, SEG_ON);
			
			display_symbol(LCD_SEG_L2_COL1, SEG_ON);
			display_symbol(LCD_SEG_L2_COL0, SEG_ON);
			
			if (sEggwatch.state != EGGWATCH_STOP) { // Blink if running or alarm triggered
			display_symbol(LCD_ICON_STOPWATCH, SEG_ON_BLINK_ON);
			}
			else { // Solid on if not running
			display_symbol(LCD_ICON_STOPWATCH, SEG_ON_BLINK_OFF);
			}
		}
		else if (update == DISPLAY_LINE_CLEAR)
		{
			// Stop blinking icon only if eggwatch isn't running
			if (sEggwatch.state == EGGWATCH_STOP) display_symbol(LCD_ICON_STOPWATCH, SEG_OFF);
		}
	}
}


// *************************************************************************************************
// @fn          eggwatch_visible
// @brief       Is eggwatch visible?
// @param       none
// @return      1=eggwatch menu currently visible, 0=menu not visible
// *************************************************************************************************
u8 eggwatch_visible(void)
{
	return (ptrMenu_L2 == &menu_L2_Eggwatch); // gibbons: currently hardcoded to Line2; change?
}

#endif //ifdef CONFIG_eggwatch
