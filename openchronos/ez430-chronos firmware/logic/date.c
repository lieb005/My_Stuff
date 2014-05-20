// *************************************************************************************************
//
//  Copyright (C) 2009 Texas Instruments Incorporated - http://www.ti.com/ 
//   
//   
//    Redistribution and use in source and binary forms, with or without 
//    modification, are permitted provided that the following conditions 
//    are met:
//  
//      Redistributions of source code must retain the above copyright 
//      notice, this list of conditions and the following disclaimer.
//   
//      Redistributions in binary form must reproduce the above copyright
//      notice, this list of conditions and the following disclaimer in the 
//      documentation and/or other materials provided with the   
//      distribution.
//   
//      Neither the name of Texas Instruments Incorporated nor the names of
//      its contributors may be used to endorse or promote products derived
//      from this software without specific prior written permission.
//  
//    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
//    "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
//    LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
//    A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
//    OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
//    SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
//    LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
//    DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
//    THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
//    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
//    OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// *************************************************************************************************
// Date functions.
// *************************************************************************************************


// *************************************************************************************************
// Include section

// system
#include "project.h"

// driver
#include "display.h"
#include "ports.h"

// logic
#include "date.h"
#include "clock.h"
#include "user.h"
#include "display2.h"


// *************************************************************************************************
// Prototypes section
void reset_date(void);
u8 get_numberOfDays(u8 month, u16 year);
void add_day(void);
void mx_date(u8 line);
void sx_date(u8 line);
void display_date(u8 line, u8 update);
void display_time_line2(u8 TimeLine2ViewStyle);


// *************************************************************************************************
// Defines section
#define DISPLAY_ALTERNATIVE_VIEW_2		(2u)
#define DISPLAY_ALTERNATIVE_VIEW_3		(3u)


// *************************************************************************************************
// Global Variable section
struct date sDate;  

u8 SecondTimeOffset;

// Segment position:
//   A
// F   B
//   G
// E   C
//   D

const u8 DayStr[7][3] = {   
    // Sun
    { SEG_A+      SEG_C+SEG_D+      SEG_F+SEG_G,     //    S
                  SEG_C+SEG_D+SEG_E            ,     //    u
                  SEG_C+      SEG_E+      SEG_G  },  //    n
    // Mo
    { SEG_A+SEG_B+            SEG_E+SEG_F      ,     //    1/2 M
      SEG_A+SEG_B+SEG_C+            SEG_F      ,     //    2/2 M
                  SEG_C+SEG_D+SEG_E+      SEG_G  },  //    o
    // Tu
    { SEG_A                                    ,     //    1/2 T
      SEG_A+                  SEG_E+SEG_F      ,     //    2/2 T
                  SEG_C+SEG_D+SEG_E              },  //    u
    // WE
    {             SEG_C+SEG_D+SEG_E+SEG_F      ,     //    1/2 W
            SEG_B+SEG_C+SEG_D+SEG_E            ,     //    1/2 W
      SEG_A+            SEG_D+SEG_E+SEG_F+SEG_G  },  //    E
    // Th
    { SEG_A                                    ,     //    1/2 T
      SEG_A+                  SEG_E+SEG_F      ,     //    2/2 T
                  SEG_C+      SEG_E+SEG_F+SEG_G  },  //    h
    // Fri
    { SEG_A+                  SEG_E+SEG_F+SEG_G,     //    F
                              SEG_E+      SEG_G,     //    r
                              SEG_E              },  //    i
    // SAt
    { SEG_A+      SEG_C+SEG_D+      SEG_F+SEG_G,     //    S
      SEG_A+SEG_B+SEG_C+      SEG_E+SEG_F+SEG_G,     //    A
                        SEG_D+SEG_E+SEG_F+SEG_G  }   //    t
};


// *************************************************************************************************
// Extern section
extern void (*fptr_lcd_function_line1)(u8 line, u8 update);
extern void (*fptr_lcd_function_line2)(u8 line, u8 update);


// *************************************************************************************************
// @fn          reset_date
// @brief       Reset date to start value.
// @param       none
// @return      none
// *************************************************************************************************
void reset_date(void)
{
    // Set date 
    sDate.year  = 2011;
    sDate.month = 1;
    sDate.day   = 1;
    sDate.DayOfWeek = 6;        // 2011-01-01 was a Saturday
    // Show day and month on display
    sDate.display = DISPLAY_DEFAULT_VIEW;
    
    SecondTimeOffset = 0;
}


// *************************************************************************************************
// @fn          display_DayOfWeek
// @brief       Display routine for Day of Week
// @param       u8 segments     LCD segments where value is displayed
//              u32 value       Integer value to be displayed
//              u8 digits       Number of digits to convert - not used
//              u8 blanks       Number of leadings blanks in itoa result string - not used
// @return      none
// *************************************************************************************************
void display_DayOfWeek(u8 segments, u32 value, u8 digits, u8 blanks)
{
   display_charSegments(LCD_SEG_L2_4, DayStr[value][0], SEG_ON_BLINK_ON);
   display_charSegments(LCD_SEG_L2_3, DayStr[value][1], SEG_ON_BLINK_ON);
   display_charSegments(LCD_SEG_L2_2, DayStr[value][2], SEG_ON_BLINK_ON);
}


// *************************************************************************************************
// @fn          get_NumberOfDays
// @brief       Return number of days for a given month
// @param       month       month as char
//              year        year as int
// @return                  day count for given month
// *************************************************************************************************
u8 get_numberOfDays(u8 month, u16 year)
{
   switch(month)
   {
      case 1:   
      case 3:   
      case 5:   
      case 7:   
      case 8:   
      case 10: 
      case 12:  return (31);

      case 4:   
      case 6:   
      case 9:   
      case 11:  return (30);

      // 1. A year that is divisible by 4 is a leap year. (Y % 4) == 0
      // 2. Exception to rule 1: a year that is divisible by 100 is not a leap year. (Y % 100) != 0
      // 3. Exception to rule 2: a year that is divisible by 400 is a leap year. (Y % 400) == 0 
   
      case 2:   if ((year%4==0) && ((year%100!=0) || (year%400==0)))    
                    return (29);
                else
                    return (28);
                
      default:  return (0);
   }
}


// *************************************************************************************************
// @fn          add_day
// @brief       Add one day to current date. Called when clock changes from 23:59 to 00:00
// @param       none
// @return      none
// *************************************************************************************************
void add_day(void)
{
    // Add 1 day
    sDate.day++;    
    if(sDate.DayOfWeek >= 6) 
    {
        sDate.DayOfWeek = 0;
    }
    else
    {
        sDate.DayOfWeek++;
    }
    
    // Check if day overflows into next month
    if (sDate.day > get_numberOfDays(sDate.month, sDate.year))
    {
        // Add 1 month and reset to day to 1
        sDate.day = 1;              
        sDate.month++;  
        
        // Check if month overflows into next year
        if (sDate.month > 12)
        {
            // Add 1 year and reset month and day to 1
            sDate.day = 1;              
            sDate.month = 1;    
            sDate.year++;
        }   
    }
    
    // Indicate to display function that new value is available
    display.flag.full_update = 1;
}


// *************************************************************************************************
// @fn          mx_date
// @brief       Date set routine.
// @param       line        LINE1, LINE2
// @return      none
// *************************************************************************************************
void mx_date(u8 line)
{
    u8 select;
    s32 day;
    s32 DayOfWeek;
    s32 month;
    s32 year;
    s32 SecondTimeOffsetTmp;
    s16 max_days;
    u8 * str;
    u8 * str1;
            
    // Clear display
    clear_display_all();
            
    // Convert global to local variables
    day       = sDate.day;
    DayOfWeek = sDate.DayOfWeek;
    month     = sDate.month;
    year      = sDate.year;
    SecondTimeOffsetTmp = SecondTimeOffset;
    
    // Init value index
    select = 0; 
    
    // Init display
    // LINE1: DD.MM (metric units) or MM.DD (English units)
    // LINE2: YYYY (will be drawn by set_value)
    
    if (sys.flag.use_metric_units)
    {
        str = itoa(day, 2, 0);
        display_chars(LCD_SEG_L1_3_2, str, SEG_ON);

        str1 = itoa(month, 2, 0);
        display_chars(LCD_SEG_L1_1_0, str1, SEG_ON);
    }
    else // English units
    {
        str = itoa(day, 2, 0);
        display_chars(LCD_SEG_L1_1_0, str, SEG_ON);

        str1 = itoa(month, 2, 0);
        display_chars(LCD_SEG_L1_3_2, str1, SEG_ON);
    }
    display_symbol(LCD_SEG_L1_DP1, SEG_ON);

    // Loop values until all are set or user breaks set
    while(1) 
    {
        // Idle timeout: exit without saving 
        if (sys.flag.idle_timeout) break;

        // Button STAR (short): save, then exit 
        if (button.flag.star) 
        {
            // Copy local variables to global variables
            sDate.day = day;
            sDate.DayOfWeek = DayOfWeek;
            sDate.month = month;
            sDate.year = year;
            SecondTimeOffset = SecondTimeOffsetTmp;
            // Full display update is done when returning from function
            break;
        }

        switch (select)
        {
            case 0:     // Set year
                        clear_line(LINE2);
                        set_value(&year, 4, 0, 2011, 2100, SETVALUE_DISPLAY_VALUE + SETVALUE_NEXT_VALUE, LCD_SEG_L2_3_0, display_value1);
                        select = 1;
                        break;
            case 1:     // Set month
                        if (sys.flag.use_metric_units) 
                        {
                            set_value(&month, 2, 0, 1, 12, SETVALUE_ROLLOVER_VALUE + SETVALUE_DISPLAY_VALUE + SETVALUE_NEXT_VALUE, LCD_SEG_L1_1_0, display_value1);
                        }
                        else // English units
                        {
                            set_value(&month, 2, 0, 1, 12, SETVALUE_ROLLOVER_VALUE + SETVALUE_DISPLAY_VALUE + SETVALUE_NEXT_VALUE, LCD_SEG_L1_3_2, display_value1);
                        }
                        select = 2;
                        break;
            case 2:     // Set day
                        if (sys.flag.use_metric_units)
                        {
                            set_value(&day, 2, 0, 1, max_days, SETVALUE_ROLLOVER_VALUE + SETVALUE_DISPLAY_VALUE + SETVALUE_NEXT_VALUE, LCD_SEG_L1_3_2, display_value1);
                        }
                        else // English units
                        {
                            set_value(&day, 2, 0, 1, max_days, SETVALUE_ROLLOVER_VALUE + SETVALUE_DISPLAY_VALUE + SETVALUE_NEXT_VALUE, LCD_SEG_L1_1_0, display_value1);
                        }
                        select = 3;
                        break;
            case 3:     // Set day of week
                        clear_line(LINE2);
                        set_value(&DayOfWeek, 1, 0, 0, 6, SETVALUE_ROLLOVER_VALUE + SETVALUE_DISPLAY_VALUE + SETVALUE_NEXT_VALUE, LCD_SEG_L2_4_0, display_DayOfWeek);
                        select = 4;
                        break;
            
            case 4:     // Set offset for second time (only hours)
                        clear_line(LINE2);
                        set_value(&SecondTimeOffsetTmp, 2, 1, 0, 23, SETVALUE_ROLLOVER_VALUE + SETVALUE_DISPLAY_VALUE + SETVALUE_NEXT_VALUE, LCD_SEG_L2_1_0, display_value1);
                        select = 0;
                        break;
        }
        
        // Check if day is still valid, if not clamp to last day of current month
        max_days = get_numberOfDays(month, year);
        if (day > max_days) day = max_days;
    }
    
    // Clear button flag
    button.all_flags = 0;
}


// *************************************************************************************************
// @fn          sx_date
// @brief       Date user routine. Toggles view between DD.MM and YYYY.
// @param       line        LINE1, LINE2
// @return      none
// *************************************************************************************************
void sx_date(u8 line)
{
    // Toggle display items
    if (sDate.display == DISPLAY_DEFAULT_VIEW) { sDate.display = DISPLAY_ALTERNATIVE_VIEW; }
    else if (sDate.display == DISPLAY_ALTERNATIVE_VIEW  ) { sDate.display = DISPLAY_ALTERNATIVE_VIEW_2; }
    else if (sDate.display == DISPLAY_ALTERNATIVE_VIEW_2) { sDate.display = DISPLAY_ALTERNATIVE_VIEW_3; }
    else { sDate.display = DISPLAY_DEFAULT_VIEW; }
}


// *************************************************************************************************
// @fn          display_date
// @brief       Display date in DD.MM format (metric units) or MM.DD (English units).
// @param       u8 line         LINE1, LINE2
//              u8 update       DISPLAY_LINE_UPDATE_FULL, DISPLAY_LINE_UPDATE_PARTIAL, DISPLAY_LINE_CLEAR
// @return      none
// *************************************************************************************************
void display_date(u8 line, u8 update)
{
    u8 * str;
    
    if (update == DISPLAY_LINE_UPDATE_FULL)         
    {
        if (sDate.display == DISPLAY_DEFAULT_VIEW)  // DD:MM
        {
            // Convert day to string
            str = itoa(sDate.day, 2, 0);
            if (sys.flag.use_metric_units)
            {   
                display_chars(switch_seg(line, LCD_SEG_L1_3_2, LCD_SEG_L2_3_2), str, SEG_ON);
            }
            else
            {
                display_chars(switch_seg(line, LCD_SEG_L1_1_0, LCD_SEG_L2_1_0), str, SEG_ON);
            }

            // Convert month to string
            str = itoa(sDate.month, 2, 0);
            if (sys.flag.use_metric_units)
            { 
                display_chars(switch_seg(line, LCD_SEG_L1_1_0, LCD_SEG_L2_1_0), str, SEG_ON);
            }
            else
            {
                display_chars(switch_seg(line, LCD_SEG_L1_3_2, LCD_SEG_L2_3_2), str, SEG_ON);
            }
            
            // Display "." to separate day and month
            display_symbol(switch_seg(line, LCD_SEG_L1_DP1, LCD_SEG_L2_DP), SEG_ON);
        }
        
        else if (sDate.display == DISPLAY_ALTERNATIVE_VIEW) // DoW.DD
             {
                // Convert day to string
                str = itoa(sDate.day, 2, 1);
                display_chars(LCD_SEG_L2_1_0, str, SEG_ON);
                // Display decimal point
                display_symbol(LCD_SEG_L2_DP, SEG_ON);
                //display_chars(LCD_SEG_L2_4_0, (u8 *)DayStr[sDate.DayOfWeek], SEG_ON);
                display_charSegments(LCD_SEG_L2_4, DayStr[sDate.DayOfWeek][0], SEG_ON);
                display_charSegments(LCD_SEG_L2_3, DayStr[sDate.DayOfWeek][1], SEG_ON);
                display_charSegments(LCD_SEG_L2_2, DayStr[sDate.DayOfWeek][2], SEG_ON);
             }
             
             else if(sDate.display == DISPLAY_ALTERNATIVE_VIEW_2) // YYYY
                  {
                     // Convert year to string
                     str = itoa(sDate.year, 4, 0);
                     display_chars(switch_seg(line, LCD_SEG_L1_3_0, LCD_SEG_L2_3_0), str, SEG_ON);
                  
                     // Clear "." 
                     display_symbol(switch_seg(line, LCD_SEG_L1_DP1, LCD_SEG_L2_DP), SEG_OFF);
                  }
                  
                  else if(sDate.display == DISPLAY_ALTERNATIVE_VIEW_3) // 2.Time HH:MM
                       {
                           u8 hour;
	
	                       // Calculate hour offset
	                       hour = sTime.hour + SecondTimeOffset;
	                       if(hour > 23) { hour -= 24; }
	                    
	                    	// Display 24H time "HH" 
	                    	display_chars(LCD_SEG_L2_3_2, itoa(hour, 2, 0), SEG_ON);
	                    	
	                    	// Display minute
	                    	display_chars(LCD_SEG_L2_1_0, itoa(sTime.minute, 2, 0), SEG_ON); 
	                    	
	                    	// Display blinking ":"
	                    	display_symbol(LCD_SEG_L2_COL0, SEG_ON_BLINK_ON);
                       }
                       
    
    }
    else if (update == DISPLAY_LINE_UPDATE_PARTIAL)
         {
         display_symbol(LCD_SEG_L2_COL0, SEG_ON_BLINK_ON);
         }   
         
         else if (update == DISPLAY_LINE_CLEAR)
              {
                  display_symbol(LCD_SEG_L2_COL0, SEG_OFF_BLINK_OFF);
                  // Show day and month on display when coming around next time
                  // sDate.display = DISPLAY_DEFAULT_VIEW;
              }   
}


