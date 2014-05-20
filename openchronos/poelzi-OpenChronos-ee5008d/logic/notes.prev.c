#include "project.h"
#ifdef CONFIG_NOTES_PREVIOUS
#include "notes.prev.h"
extern struct previous_notes prev_notes = 
{
	.notes =
	{
		(u8*)"NOTE0",
		(u8*)"NOTE1",
		(u8*)"NOTE2",
		(u8*)"NOTE3",
		(u8*)"NOTE4",
		(u8*)"NOTE5",
		(u8*)"NOTE6",
		(u8*)"NOTE7",
		(u8*)"NOTE8",
		(u8*)"NOTE9"
	},
	.size =
	{
		5,
		5,
		5,
		5,
		5,
		5,
		5,
		5,
		5,
		5
	}
};
#endif
