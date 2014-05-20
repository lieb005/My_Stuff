#ifndef GLOBALFUNCTIONS_H_
#define GLOBALFUNCTIONS_H_
extern void (*update_blink_function)(u8 digit, u8 line);
extern struct global * caller;
extern void set_var(u8* var, u8 ** data, u8 min, u8 max, u16 seg);
extern void set_alphanum_value(u8 * value, u8 * charnum, u8 select, u8 * pos, struct global * caller, u8 line);
extern u8 numexit;
struct global
{
	void (*update_function)(void);
	void (*update_function_blink)(u8 digit, u8 line);
	u8 caller;
};
#ifdef CONFIG_NOTES
extern struct global sGlobal_notes;
#define CALLER_NOTES		(0u)
#endif
#ifdef CONFIG_CALENDAR
extern struct global sGlobal_calendar;
#define CALLER_CALENDAR 	(1u)
#endif

#define FUNCTION(function) function

// finds the Absolute Value of a number.  MUST PASS A SIGNED NUMBER TO BE EFFECTIVE!!!!
#define ABS(a) ((a)>=0?(a):(-(a)))
// returns the size of an array
#define ARRAY_SIZE(arr) (sizeof(arr)/sizeof(arr[0]))
// the size of the font for the display
#define LCD_FONT_SIZE 52
// returns the hex value of a character to display
#define LCD_CHARS(a) ((a)>2&&(a)<LCD_FONT_SIZE-1?(a)+0x2D:((a)==0?0x2D:((a)==1?0x20:0x2D+(a))))

#endif
