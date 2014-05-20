#ifndef METRONOME_H_
#define METRONOME_H_
extern void display_metronome(u8 line, u8 update);
extern void mx_metronome(u8 line);
extern void sx_metronome(u8 line);
extern void nx_metronome(u8 line);
extern u8 update_metronome(void);
extern void start_metronome(void);
extern void stop_metronome(void);
extern u8 is_metronome(void);

struct metronome
{
	u8 rate; // in bpm
	u8 state;
};
#endif