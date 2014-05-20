#ifndef PREV_NOTES_H_
#define PREV_NOTES_H_
struct previous_notes
{
	u8 * notes[10];
	u8 size[10];
};
extern struct previous_notes prev_notes;
#endif
