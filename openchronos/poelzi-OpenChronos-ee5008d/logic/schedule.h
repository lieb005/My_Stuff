#ifndef SCHEDULE_H_
#define SCHEDULE_H_
extern void sx_schedule(u8 line);
extern void mx_schedule(u8 line);
extern u8 update_schedule();
extern void update_schedule_time(void);
extern void display_schedule(u8 line, u8 update);
extern u8 is_schedule();

#define SCHEDULE_DISABLED	(0u)
#define SCHEDULE_ENABLED	(1u)
#define SCHEDULE_NONE		(2u)

#define PERIOD			(0u)
#define TIME			(1u)

struct schedule
{
	u8 * period;
	u16 end;
	u8 dayOfWeek;
	u8 state;
	u8 currentlyShown;
};

extern struct schedule sSchedule;
#endif
