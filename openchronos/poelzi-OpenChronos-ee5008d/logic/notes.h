#ifndef NOTES_H_
#define NOTES_H_

// menu functions
// switch function (up/down short) -> goes to next note
extern void sx_notes(u8 line);
// next menu item function (star/num short) -> stops scrolling and moves to next menu item
extern void nx_notes(u8 line);
// set function (star/num long) -> is what iit says it does, sets the note (star long = reset, num long = new digit, up down = up down letter/number)
extern void mx_notes(u8 line);
// misc function (up/down long) -> start scrolling
extern void dx_notes(u8 line);
// displays the note, same as update_notes
extern void display_notes(u8 line, u8 update);
// is notes the currently shown item?
extern u8 is_notes(void);
// displays the current note
extern u8 update_notes(void);
// displays the current note with one digit blinking.  used for all display functions.  pass 0-4 to blink a digit, any other # is no-blinking.
// update_notes and display_notes passes -1 (it's an unsigned number, so is actually the highest possible number, which will never be a digit)
extern void update_notes_blink(u8 digit, u8 line);
// advances scrolling of note
extern void tick_notes(void);
// starts scrolling of note
extern void start_notes(void);
// stops scrolling of note
extern void stop_notes(void);
// resets thee note back to ######
extern void reset_note(u8 noteNum);

#ifdef CONFIG_NOTES_PREVIOUS
// pretty self explanatory
extern void load_notes_prev(void);
#endif

#define SNOTES_TIMER_OFF	(0u)
#define SNOTES_TIMER_ON		(1u)
#define NOTES_DEFAULT_MAX	(6u)

struct notes
{
	// current note being displayed
	u16 current;
	// segments to display during scrolling
	u8 * seg[5];
	// Note data.  first array is the note (10 total), second content (max 20 characters), third: 0 = unicode char val, 1 = font val
	u8 notes[10][20][2];
	// sizes of the notes
	u8 size[10];
	// Scroll enable state
	u8 state;
	// Current scroll position
	u16 pos;
};
extern struct notes sNotes;


#endif /* NOTES_H_ */
