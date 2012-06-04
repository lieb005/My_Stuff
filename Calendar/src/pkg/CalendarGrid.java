package pkg;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.MouseInfo;
import java.awt.Point;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.FocusAdapter;
import java.awt.event.FocusEvent;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Calendar;
import java.util.Date;
import java.util.Vector;

import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JWindow;
import javax.swing.event.MouseInputListener;

public class CalendarGrid extends JPanel implements MouseListener
{
	public final static boolean	INPUT_MONTH	= false;
	private GridBagConstraints	constraints	= new GridBagConstraints ();
	// 7 days a week, 5 weeks long
	// width x height in squares
	private Day[][]				days		= new Day[7][6];
	private int					first, month, year;
	private JWindow				popup		= new JWindow ();

	public CalendarGrid (int month, int year)
	{
		this.month = month;
		this.year = year;
		GridBagLayout gL = new GridBagLayout ();
		setLayout (gL);
		Calendar timeTravel = Calendar.getInstance ();
		boolean brk = false;
		// timeTravel.setTimeInMillis (System.currentTimeMillis ());
		if (INPUT_MONTH)
		{
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
		}
		else
		{
			timeTravel.set (Calendar.MONTH, month);
			timeTravel.set (Calendar.YEAR, year);
		}
		System.out.println (timeTravel.get (Calendar.DAY_OF_MONTH));
		System.out.println (timeTravel.get (Calendar.MONTH) + 1);
		System.out.println (timeTravel.get (Calendar.YEAR));
		System.out.println ("\n\n\n\n");
		timeTravel.set (Calendar.WEEK_OF_MONTH, 1);
		timeTravel.set (Calendar.DAY_OF_MONTH, 1);
		first = timeTravel.get (Calendar.DAY_OF_WEEK);
		int day = 0, d = 0;
		for (int w = 0; w < 6 && !brk; w++)
		{
			timeTravel.set (Calendar.WEEK_OF_MONTH, w + 1);
			if (w == 0)
				timeTravel.set (Calendar.DAY_OF_MONTH, 1);
			for (d = (w == 0) ? first - 1 : 0; d < 7; d++)
			{
				timeTravel.set (Calendar.DAY_OF_WEEK, d + 1);
				// always comes up short one
				if (brk)
				{
					break;
				}
				if ( (timeTravel.getActualMaximum (Calendar.DAY_OF_MONTH) == ++day))
				{
					brk = true;
				}
				days[d][w] = new Day (d, day);
				constraints.anchor = GridBagConstraints.CENTER;
				constraints.fill = GridBagConstraints.BOTH;
				constraints.gridx = d;
				constraints.gridy = w;
				add (days[d][w], constraints);
				days[d][w].setText (String.valueOf (day));
				repaint ();
				days[d][w].tasks.add (new Task (Integer.toString (d + 1)
						+ " day of " + Integer.toString (w + 1) + " week"));
				days[d][w].addFocusListener (new FocusAdapter () {
					@Override
					public void focusLost (FocusEvent e)
					{
						super.focusLost (e);
						System.out.println ("focus lost day");
						System.out.println (e.getSource ());
						hidePopoup ();
					}
				});
			}
		}
		repaint ();
		addMouseListener (this);
		addFocusListener (new FocusAdapter () {
			@Override
			public void focusLost (FocusEvent e)
			{
				super.focusLost (e);
				System.out.println (e.getSource ());
				hidePopoup ();
			}
		});
	}

	public int getFirstDayOfMonth ()
	{
		return first;
	}

	public int getMonth ()
	{
		return month;
	}

	public JWindow getPopup ()
	{
		return popup;
	}

	public int getYear ()
	{
		return year;
	}

	public void hidePopoup ()
	{
		if (popup != null)
		{
			popup.setVisible (false);
			popup.dispose ();
			popup = null;
		}
	}

	@Override
	public void mouseClicked (MouseEvent e)
	{}

	@Override
	public void mouseEntered (MouseEvent e)
	{}

	@Override
	public void mouseExited (MouseEvent e)
	{}

	@Override
	public void mousePressed (MouseEvent e)
	{
		if (popup != null)
			if (! (popup.contains (e.getPoint ()) && this.contains (e
					.getPoint ())))
			{
				hidePopoup ();
			}
	}

	@Override
	public void mouseReleased (MouseEvent e)
	{}

	public void showPopup (Vector<Task> tasks, Point location)
	{
		hidePopoup ();
		popup = new JWindow ();
		popup.setAlwaysOnTop (true);
		popup.setLocation (location);
		for (int i = 0; i < tasks.size (); i++)
		{
			popup.add (new JLabel (tasks.get (i).getTask ()));
		}
		popup.setVisible (true);
		popup.pack ();
	}
}

class Day extends JButton implements ActionListener, MouseInputListener
{
	public static final int	NONE	= 0, OVER = 1, DOWN = 2;

	private int				dayOfWeek, date;
	public int				mouseState;
	public Vector<Task>		tasks	= new Vector<Task> ();

	public Day (int dayOfWeek, int date)
	{
		this.dayOfWeek = dayOfWeek;
		this.date = date;
		addActionListener (this);
		addMouseListener (this);
		setPreferredSize (new Dimension (64, 64));
	}

	@Override
	public void actionPerformed (ActionEvent e)
	{
		// show task bubble/window thing here
		getParent ().showPopup (tasks,
				MouseInfo.getPointerInfo ().getLocation ());
		System.out.println (e.getSource ());
		if (! (e.getSource () instanceof CalendarGrid && e.getSource () instanceof Day))
			getParent ().hidePopoup ();
		repaint ();
	}

	public int getDate ()
	{
		return date;
	}

	public int getDayOfWeek ()
	{
		return dayOfWeek;
	}

	@Override
	public CalendarGrid getParent ()
	{
		return (CalendarGrid) super.getParent ();
	}

	@Override
	public void mouseClicked (MouseEvent e)
	{
		if (contains (e.getPoint ()))
		{
			mouseState = DOWN;
			repaint ();
			mouseState = OVER;
			repaint ();
		}
	}

	@Override
	public void mouseDragged (MouseEvent e)
	{
		if (contains (e.getPoint ()))
		{
			mouseState = DOWN;
			repaint ();
		}
	}

	@Override
	public void mouseEntered (MouseEvent e)
	{
		if (contains (e.getPoint ()))
		{
			mouseState = OVER;
			repaint ();
		}
	}

	@Override
	public void mouseExited (MouseEvent e)
	{
		mouseState = NONE;
		repaint ();
	}

	@Override
	public void mouseMoved (MouseEvent e)
	{
		if (contains (e.getPoint ()))
		{
			mouseState = OVER;
			repaint ();
		}
	}

	@Override
	public void mousePressed (MouseEvent e)
	{
		if (contains (e.getPoint ()))
		{
			mouseState = DOWN;
			repaint ();
		}
	}

	@Override
	public void mouseReleased (MouseEvent e)
	{
		if (contains (e.getPoint ()))
		{
			mouseState = OVER;
			repaint ();
		}
	}

	public void paint (Graphics g)
	{
		super.paint (g);
		int w = g.getClipBounds ().width, h = g.getClipBounds ().height;
		g.clearRect (0, 0, w, h);
		if (mouseState == NONE)
			g.setColor (Color.WHITE);
		else if (mouseState == OVER)
			g.setColor (Color.LIGHT_GRAY);
		else
			g.setColor (Color.GRAY);
		g.fillRect (0, 0, w - 1, h - 1);
		if (mouseState != DOWN)
			g.setColor (Color.BLACK);
		else
			g.setColor (Color.WHITE);
		g.drawRect (0, 0, w - 1, h - 1);
		g.setFont (Font.getFont (Font.MONOSPACED));
		// 15 & 17 are random values that worked
		g.drawChars (String.format ("%2d", date).toCharArray (), 0, 2, 15, 17);
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
	private int				repeats	= 0;
	private Date			start	= null, end = null;
	private String			task	= "";

	public Task (String task)
	{
		this.task = task;
	}

	public Date getEndTime ()
	{
		return end;
	}

	public int getRepititions ()
	{
		return repeats;
	}

	public Date getStartTime ()
	{
		return start;
	}

	public String getTask ()
	{
		return task;
	}

	public void setEndTime (Date d)
	{
		end = d;
	}

	public void setRepetition (int rep)
	{
		repeats = rep;
	}

	public void setStartTime (Date d)
	{
		start = d;
	}

	public void setTask (String s)
	{
		task = s;
	}
}
