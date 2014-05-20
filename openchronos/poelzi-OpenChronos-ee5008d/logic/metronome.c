#include "project.h"

#ifdef CONFIG_METRONOME
#include "user.h"
#include "display.h"
#include "metronome.h"
#include "buzzer.h"
#include "timer.h"
#include "menu.h"

void display_metronome (u8 line, u8 update)
{
	if (update == DISPLAY_UPDATE_PARTIAL)
	{
		
	}
	else if (update == DISPALY_UPDATE_FULL)
	{
		
	}
}
void mx_metronome (u8 line)
{
	
}
void sx_metronome (u8 line)
{
	
}
void nx_metronome (u8 line)
{
	
}
u8 update_metronome (void)
{
	
}
void start_metronome (void)
{
	u16 time_on = ((60/bpm)*32768)-50;
	u8 cycles;
	start_buzzer (cycles
}
void stop_metronome (void)
{
	stop_buzzer();
}
u8 is_metronome (void)
{
	return (ptrMenu_L1 == &menu_L1_Metronome);
}
#endif
