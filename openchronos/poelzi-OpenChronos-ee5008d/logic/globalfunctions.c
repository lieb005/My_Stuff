#include "project.h"
#ifdef CONFIG_GLOBALFUNCTIONS
// driver
#include "display.h"
#include "ports.h"
#include "buzzer.h"


// logic
#include "user.h"

#include "menu.h"
#ifdef CONFIG_NOTES
#include "notes.h"
#endif
#ifdef CONFIG_CALENDAR
#include "calendar.h"
#endif
#include "globalfunctions.h"

u8 numexit;
u8 * size;
extern void idle_loop(void);

void set_var(u8 * var, u8 ** data, u8 min, u8 max, u16 seg)
{
	// Clear button flags
	button.all_flags = 0;
	
	// Clear blink memory
	clear_blink_mem();
	
	// For safety only - buzzer on/off and button_repeat share same IRQ
	stop_buzzer();
	
	// Init step size and repeat counter
	sButton.repeats = 1;
	
	// Turn on 125ms button repeat function 
	button_repeat_on(125);
	
	// Start blinking with with 2Hz
	set_blink_rate(BIT6 + BIT5);
	while(1)
	{
		// Idle timeout: exit function
		if (sys.flag.idle_timeout)	break;
		// Button NUM (short) button: exit parent function
		if (button.flag.num)		break;
		
		if (button.flag.up)
		{
			(*var)++;
			if(*var > max)
			{
				*var = min;
			}
		}
		if (button.flag.down)
		{
			if(*var <= min)
			{
				*var = max;
			}
			else
			{
				(*var)--;
			}
		}
		display_chars(seg, data[*var], SEG_ON_BLINK_ON);
	}
	// Set blinking rate to 1Hz and stop
	set_blink_rate(BIT7 + BIT6 + BIT5);
	// clear blink mem
	clear_blink_mem();
	// Turn off button repeat function
	button_repeat_off();
	// Clear button flag
	button.all_flags = 0;
}

void set_alphanum_value(u8 * value, u8 * charnum, u8 select, u8 * pos, struct global * caller, u8 line)
{
	u8 update;
	u8 digit;
	#ifdef CONFIG_NOTES
	if (caller->caller == CALLER_NOTES)
	{
		size = &sNotes.size[sNotes.current];
	}
	#endif
	#ifdef CONFIG_CALENDAR
	if (caller->caller == CALLER_CALENDAR)
	{
		size = &sCalendar.days[current_day].agenda[current_agendum].size;
	}
	#endif
	clear_display();
	// Initial display update
	update = 1;
	
	// Clear button flags
	button.all_flags = 0;
	
	// Clear blink memory
	clear_blink_mem();
	
	// For safety only - buzzer on/off and button_repeat share same IRQ
	stop_buzzer();
		
	// Init step size and repeat counter
	sButton.repeats = 1;
	
	// Turn on 125ms button repeat function 
	button_repeat_on(125);
	
	// Start blinking with with 2Hz
	set_blink_rate(BIT6 + BIT5);

	// Value set loop
	while(!numexit) 
	{
		// Idle timeout: exit function
		if (sys.flag.idle_timeout)	numexit = 1;
		// Button STAR (short) button: exit function
		if (button.flag.star)		break;
		// Button NUM (short) button: exit parent function
		if (button.flag.num)		numexit = 1;
		// Button STAR (long) button: reset note
		if (button.flag.star_long)
		{
			#ifdef CONFIG_NOTES
			if (caller->caller == CALLER_NOTES)
			{
				reset_note(sNotes.current);
			}
			#endif
			#ifdef CONFIG_CALENDAR
			if (caller->caller == CALLER_CALENDAR)
			{
				reset_calendar_agendum(current_agendum);
			}
			#endif
		}
		// Button NUM (long) button: new caharacter added on end.  
		if (button.flag.num_long)
		{
			u8 num = 0;
			#ifdef CONFIG_NOTES
			if (caller->caller == CALLER_NOTES)
			{
				num = sNotes.current;
			}
			#endif
			#ifdef CONFIG_CALENDAR
			if (caller->caller == CALLER_CALENDAR)
			{
				num = current_agendum;
			}
			#endif
			// Increase size by one
			(*size)++;
			// initialize new digit to #
			*value = 0x30 + num;
			*charnum = 0;
			// move to next digit if last is selected
			if (*pos == (*size)-2) (*pos)++;
			// update notes
			caller->update_function();
			// clear num_long flag so must re-press button to register again
			button.flag.num_long = 0;
		}
		// UP button: increase value
		if(button.flag.up)
		{
			// Increase value
			if(*charnum < LCD_FONT_SIZE)
			{
				++(*charnum);
				// make sure not blank
				while((lcd_font[LCD_CHARS(*charnum)-0x30] == 0 || LCD_CHARS(*charnum) == 0x2E || LCD_CHARS(*charnum) == 0x2F) && !LCD_CHARS(*charnum) == 0x20)
				{
					if(*charnum >= LCD_FONT_SIZE)
					{
							*charnum = 0;
							continue;
					}
					++(*charnum);
				}
				if (*charnum >= LCD_FONT_SIZE + 3)	*charnum = 0;
			}
			// Trigger display update
			update = 1;
			
			// Clear button flag
			button.flag.up = 0;
		}
		// DOWN button: decrease value
		if(button.flag.down)
		{
			// Increase value
			if(*charnum >= 0)
			{
				--(*charnum);
				// make sure not blank
				while((lcd_font[LCD_CHARS(*charnum)-0x30] == 0 || LCD_CHARS(*charnum) == 0x2E || LCD_CHARS(*charnum) == 0x2F) && !LCD_CHARS(*charnum) == 0x20)
				{
					if(*charnum > LCD_FONT_SIZE)
					{
						*charnum = LCD_FONT_SIZE - 1;
						continue;
					}
					--(*charnum);
				}
			}
			if (*charnum > LCD_FONT_SIZE) *charnum = LCD_FONT_SIZE - 1;
		}
		// Trigger display update
		update = 1;
		// Clear button flag	
		button.flag.down = 0;
		// Update display when there is new data
		if (update)
		{
			*value = LCD_CHARS(*charnum);
			digit = select<2?select:(select>(*size)-3)?5-((*size)-select):2;
			// redraw blinking
			caller->update_function_blink(digit, line);
			// Clear update flag
			update = 0;
		}
		// Call idle loop to serve background tasks
		idle_loop();
	}
	
	// Set blinking rate to 1Hz and stop
	set_blink_rate(BIT7 + BIT6 + BIT5);
	// clear blink mem
	clear_blink_mem();
	// Turn off button repeat function
	button_repeat_off();
	// Clear button flag
	button.all_flags = 0;
}
#endif
