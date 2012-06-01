package pkg;

import java.awt.Graphics;
import java.awt.GridLayout;
import java.util.Calendar;

import javax.swing.JButton;
import javax.swing.JPanel;

public class CalendarGrid extends JPanel
{
	private int	first, month, year;
	// 7 days a week, 5 weeks long
	Day[][]		days	= new Day[7][5];	// width x height in squares

	public CalendarGrid (int first, int month, int year)
	{
		this.first = first;
		this.month = month;
		this.year = year;
		GridLayout gL = new GridLayout (5, 7, 0, 0);
		setLayout (gL);
		Calendar c = Calendar.getInstance ();
		Calendar timeTravel = Calendar.getInstance ();
		boolean brk = false, firstLoop = true;;
		for (int w = 0; w < 5 && !brk; w++)
		{
			for (int d = firstLoop ? c.get (Calendar.DAY_OF_MONTH) % 7 - 1 : 0; d < 7; d++)
			{
				timeTravel.set (Calendar.WEEK_OF_MONTH, w + 1);
				if (timeTravel.getActualMaximum (Calendar.DAY_OF_WEEK) <= d && timeTravel.getActualMaximum (Calendar.DAY_OF_WEEK) < 7)
					brk = true;
				days[d][w] = new Day (d, 7 * w + d + 1);
				add (days[d][w]);
			}
			firstLoop = false;
		}
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

class Day extends JButton
{
	private int	dayOfWeek, date;

	public Day (int dayOfWeek, int date)
	{
		this.dayOfWeek = dayOfWeek;
		this.date = date;
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
		// g.setColor (Color.WHITE);
		// g.fillRect (0, 0, w, h);
		// g.setColor (Color.BLACK);
		// g.drawRect (0, 0, w, h);
	}
}
