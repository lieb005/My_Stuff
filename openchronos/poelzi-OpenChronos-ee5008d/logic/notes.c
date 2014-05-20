#include "../include/project.h"
#ifdef CONFIG_NOTES

// driver
#include "display.h"
#include "ports.h"
#include "buzzer.h"


// logic
#include "user.h"

#include "menu.h"
#include "notes.h"
#include "globalfunctions.h"
#include "notes.prev.h"

struct notes sNotes;
struct global sGlobal_notes = 
{
	&update_notes,
	&update_notes_blink,
	CALLER_NOTES
};

// returns the size of an array
#define ARRAY_SIZE(arr) (sizeof(arr)/sizeof(arr[0]))
// the size of the font for the display
#define LCD_FONT_SIZE 52
// returns the hex value of a character to display
#define LCD_CHARS(a) ((a)>2&&(a)<LCD_FONT_SIZE-1?(a)+0x2D:((a)==0?0x2D:((a)==1?0x20:0x2D+(a))))

extern void menu_skip_next(line_t line); // in ezchronos.c

void sx_notes(u8 line)
{
	if (button.flag.down)
	{
		stop_notes();
		sNotes.current++;
		if (sNotes.current > 9)
		{
			sNotes.current = 0;
		}
		update_notes();
	}
}
#ifdef CONFIG_NOTES_PREVIOUS
void load_notes_prev()
{
	u8 i = 0;
	for (;i<10;i++)
	{
		sNotes.size[i] = prev_notes.size[i];
		u8 j = 0;
		for (;j<20;j++)
		{
			sNotes.notes[i][j][0] = prev_notes.notes[i][j];
			sNotes.notes[i][j][1] = 0;
		}
	}
}
#endif
void dx_notes(u8 line)
{
	// toggle scrolling
	sNotes.state==SNOTES_TIMER_ON?stop_notes():start_notes();
}

u8 update_notes()
{
	clear_line(LINE2);
	update_notes_blink(-1, 0);
	return 1;
}
void update_notes_blink(u8 digit_blink, u8 line)
{
	display_char(LCD_SEG_L2_4, sNotes.notes[sNotes.current][sNotes.pos+0][0], digit_blink==0?SEG_ON_BLINK_ON:SEG_ON_BLINK_OFF);
	display_char(LCD_SEG_L2_3, sNotes.notes[sNotes.current][sNotes.pos+1][0], digit_blink==1?SEG_ON_BLINK_ON:SEG_ON_BLINK_OFF);
	display_char(LCD_SEG_L2_2, sNotes.notes[sNotes.current][sNotes.pos+2][0], digit_blink==2?SEG_ON_BLINK_ON:SEG_ON_BLINK_OFF);
	display_char(LCD_SEG_L2_1, sNotes.notes[sNotes.current][sNotes.pos+3][0], digit_blink==3?SEG_ON_BLINK_ON:SEG_ON_BLINK_OFF);
	display_char(LCD_SEG_L2_0, sNotes.notes[sNotes.current][sNotes.pos+4][0], digit_blink==4?SEG_ON_BLINK_ON:SEG_ON_BLINK_OFF);
}

void display_notes(u8 line, u8 update)
{
	update_notes();
}

u8 is_notes(void)
{
	return (ptrMenu_L2 == &menu_L2_Notes);
}
void mx_notes(u8 line)
{
	stop_notes();
	clear_display_all();
	u8 select = 0;
	while (!numexit)
	{
		sNotes.pos = select<2?0:(select-1)>(sNotes.size[sNotes.current]-5)?sNotes.size[sNotes.current]-5:select-2;
		set_alphanum_value(&sNotes.notes[sNotes.current][select][0], &sNotes.notes[sNotes.current][select][1], select, &sNotes.pos, &sGlobal_notes, LINE2);
		if (++select >= sNotes.size[sNotes.current])	select = 0;
	}
	sNotes.pos = 0;
	numexit = 0;
	// Clear button presses
	button.all_flags = 0;
}
void tick_notes()
{
	if(sNotes.state == SNOTES_TIMER_ON){
		sNotes.pos++;
		if(sNotes.pos > sNotes.size[sNotes.current]-4)
		{
			sNotes.pos = 0;
		}
		update_notes();
	}
}

void nx_notes(u8 line)
{
	stop_notes();
	menu_skip_next(line);
}

void start_notes()
{
	sNotes.state = SNOTES_TIMER_ON;
	sNotes.pos = 0;
	display_symbol(LCD_ICON_RECORD, SEG_ON_BLINK_OFF);
}
void stop_notes()
{
	sNotes.state = SNOTES_TIMER_OFF;
	sNotes.pos = 0;
	display_symbol(LCD_ICON_RECORD, SEG_OFF);
}
void reset_note(u8 noteNum)
{
	u8 i = 0;
	for(;i<sNotes.size[noteNum];i++)
	{
		sNotes.notes[noteNum][i][0] = 0x30 + noteNum;
		sNotes.notes[noteNum][i][1] = 0;
	}
	sNotes.size[sNotes.current] = NOTES_DEFAULT_MAX;
}

#endif /* CONFIG_NOTES */
