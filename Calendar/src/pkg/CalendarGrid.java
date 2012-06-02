package pkg;

import java.awt.Graphics;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Calendar;
import java.util.Date;
import java.util.Vector;

import javax.swing.JButton;
import javax.swing.JPanel;

public class CalendarGrid extends JPanel
{
	private int			first, month, year;
	// 7 days a week, 5 weeks long
	Day[][]				days		= new Day[7][6];				// width
																	// x
																	// height
																	// in
																	// squares
	GridBagConstraints	constraints	= new GridBagConstraints ();

	public CalendarGrid (int first, int month, int year)
	{
		this.first = first;
		this.month = month;
		this.year = year;
		GridBagLayout gL = new GridBagLayout ();
		setLayout (gL);
		Calendar timeTravel = Calendar.getInstance ();
		boolean brk = false;
		// timeTravel.setTimeInMillis (System.currentTimeMillis ());
		try
		{
			timeTravel.set (Calendar.MONTH, Integer
					.valueOf (new BufferedReader (new InputStreamReader (
							System.in)).readLine ()));
		} catch (NumberFormatException e)
		{
			e.printStackTrace ();
		} catch (IOException e)
		{
			e.printStackTrace ();
		}
		timeTravel.set (Calendar.WEEK_OF_MONTH, 1);
		timeTravel.set (Calendar.DAY_OF_MONTH, 1);
		int day = 0, d = 0;
		for (int w = 0; w < 6 && !brk; w++)
		{
			timeTravel.set (Calendar.WEEK_OF_MONTH, w + 1);
			if (w == 0)
				timeTravel.set (Calendar.DAY_OF_MONTH, 1);
			for (d = (w == 0) ? (timeTravel.get (Calendar.DAY_OF_WEEK)) - 1 : 0; d < 7; d++)
			{
				System.out.println (timeTravel.get (Calendar.DAY_OF_WEEK));
				timeTravel.set (Calendar.DAY_OF_WEEK, d + 1);
				// always comes up short one
				if (brk)
				{
					break;
				}
				if ( (timeTravel.getActualMaximum (Calendar.DAY_OF_MONTH) == ++day))
				{
					brk = true;
					System.out.println ("break");
				}
				// day++;
				days[d][w] = new Day (d, day);
				constraints.anchor = GridBagConstraints.CENTER;
				constraints.fill = GridBagConstraints.BOTH;
				constraints.gridx = d;
				constraints.gridy = w;
				add (days[d][w], constraints);
				days[d][w].setSize (32, 32);
				days[d][w].setText (String.valueOf (day));
				repaint ();
				days[d][w].tasks.add (new Task (Integer.toString (d) + " day of " + Integer.toString (w) + " week"));
			}
		}
		repaint ();
	}

	public int getFirstDayOfMonth ()
	{
		return first;
	}

	public int getMonth ()
	{
		return month;
	}

	public int getYear ()
	{
		return year;
	}
}

class Day extends JButton implements ActionListener
{
	public static final int	NONE	= 0, OVER = 1, DOWN = 2;

	public int				mouseState;
	private int				dayOfWeek, date;
	public Vector<Task>		tasks = new Vector<Task> ();

	public Day (int dayOfWeek, int date)
	{
		this.dayOfWeek = dayOfWeek;
		this.date = date;
		addActionListener (this);
	}

	public int getDayOfWeek ()
	{
		return dayOfWeek;
	}

	public int getDate ()
	{
		return date;
	}

	public void paint (Graphics g)
	{
		super.paint (g);
		// int w = g.getClipBounds ().width, h = g.getClipBounds ().height;
		// g.clearRect (0, 0, w, h);
		// if (mouseState == NONE)
		// g.setColor (Color.WHITE);
		// else if (mouseState == OVER)
		// g.setColor (Color.LIGHT_GRAY);
		// else
		// g.setColor (Color.GRAY);
		// g.fillRect (0, 0, w, h);
		// g.setColor (Color.BLACK);
		// g.drawRect (0, 0, w-1, h-1);
		// g.drawChars (String.format ("%2d", date).toCharArray (), 0, 2,
		// g.getFontMetrics ().getAscent (), g.getFontMetrics ().getMaxAdvance
		// ()*2);
	}

	@Override
	public void actionPerformed (ActionEvent e)
	{
		setText (tasks.get (0).getTask ());
		repaint ();
	}
}

class Task
{
	// Specifies to repeat every ______ on at this time (If weekly, monthly, or
	// yearly, repeat on current selected day)
	static public final int	NEVER	= 0, DAILY = 1, WEEKLY = 2, MONTHLY = 3,
			YEARLY = 4;
	// repeat on specified days. Can be added and can be added with weekly,
	// monthly or yearly also.
	static public final int	SUNDAY	= 0x10, MONDAY = 0x20, TUESDAY = 0x40,
			WEDNESDAY = 0x80, THURSDAY = 0x100, FRIDAY = 0x200,
			SATURDAY = 0x400;
	private String			task	= "";
	private Date			start	= null, end = null;
	private int				repeats	= 0;

	public Task (String task)
	{
		this.task = task;
	}

	public void setTask (String s)
	{
		task = s;
	}

	public String getTask ()
	{
		return task;
	}

	public void setStartTime (Date d)
	{
		start = d;
	}

	public Date getStartTime ()
	{
		return start;
	}

	public void setEndTime (Date d)
	{
		end = d;
	}

	public Date getEndTime ()
	{
		return end;
	}

	public void setRepetition (int rep)
	{
		repeats = rep;
	}

	public int getRepititions ()
	{
		return repeats;
	}
}
