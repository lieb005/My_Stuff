#ifndef CALENDAR_H_
#define CALENDAR_H_
//set calendar superfunction
extern void mx_calendar(u8 line);
// UP: switch view (cycle through date and Alarms), Down: switch agendum or change reoccurence of alarms
extern void sx_calendar(u8 line);
// switch to next item in menu.  This stops the agenda
extern void nx_calendar(u8 line);
// up_long = toggle alarm, down_long = toggle agendum scrolling and 
extern void dx_calendar(u8 line);
// set agendum
extern void mx_calendar_agendum(void);
// set repitition of alarm
extern void mx_alarm_repitition(void);
// set alarm
extern void mx_calendar_alarm(void);
// set date
extern void mx_calendar_date(void);
// display the function on the display
extern void display_calendar(u8 line, u8 update);
// update the display (it is equal to displaying both lines)
extern u8 update_calendar(void);
// returns if calendar is being displayed currently
extern u8 is_calendar(void);
// will eventually be the super function of display and update.  It is capable of solid and blinking.
extern void update_calendar_blink(u8 digit, u8 line);
// stop the scrolling of the agendum
extern void stop_calendar_agendum(void);
// start the scrolling of the agendum
extern void start_calendar_agendum(void);
// advance the scolling of the agendum by one
extern void tick_calendar_agendum(void);
//check to see if the alarm should be going off
extern void check_alarms(void);
// check the arrows (which signify whether the alarm is on or off)
extern void check_arrow_state(void);
// check to make sure the alarm symbol is on when it is supposed to be
extern void check_alarm_symbol(void);
// stop the alarm from going off
extern void stop_calendar_alarm(void);
// reset the agendum "######" and make max size = AGENDUM_DEFAULT_SIZE
extern void reset_calendar_agendum(u8 num);
#ifdef CONFIG_SCHOOL_ALARM
// check to see if the scool alarm is right
extern void check_school_alarm(u8 * minute, u8 * hour, u8 * state);
#endif

extern u8 current_agendum;
extern u8 current_day;
extern u8 menu_L2_old_position;
extern u8 first_update;

#define VIEW_DATE		(0u)
#define VIEW_ALARM0		(1u)
#define VIEW_ALARM1		(2u)
#define VIEW_ALARM2		(3u)

#define CALENDAR_TIMER_OFF	(0u)
#define CALENDAR_TIMER_ON	(1u)

#define CALENDAR_ALARM_ENABLED	(0u)
#define CALENDAR_ALARM_DISABLED	(1u)
#define CALENDAR_ALARM_ON	(2u)

#define ALARM_REPEAT_ONCE	(0u)
#define ALARM_REPEAT_DAILY	(1u)
#define ALARM_REPEAT_WEEKLY	(2u)

#define AGENDUM_DEFAULT_SIZE	(6u)

typedef struct agendum sAgendum;
typedef struct alm sAlm;
typedef struct day sDay;
typedef struct cal calendar;
extern calendar sCalendar;
extern struct global sGlobal_notes;

struct agendum
{
	u8 * content;
	u32 charnum;
	u8 size;
	u8 state;
	u16 pos;
};
struct alm
{
	u8 hour;
	u8 minute;
	u8 repeat;
	u8 state;
};
struct day
{
	u8 day;
	u8 buzzer;
	u8 duration;
	sAgendum agenda[5];
	sAlm alarms[3];
};
struct cal
{
	u8 month;
	u16 year;
	u8 view;
	sDay days[31];
	u8 repeat_alarms[3][3];
};
#endif
