package pkg;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JApplet;
import javax.swing.JFrame;

public class Calendar extends JApplet implements ActionListener
{
	@Override
	public void actionPerformed (ActionEvent e)
	{}

	/**
	 * @param args
	 */
	public static void main (String[] args)
	{
		JFrame f = new JFrame ("Calendar");
		Calendar c = new Calendar ();
		f.add (c);
		c.init();
		c.start();
		f.setVisible (true);
		c.repaint ();
		f.setSize (900, 900);
		f.setDefaultCloseOperation (JFrame.EXIT_ON_CLOSE);
	}

	@Override
	public void init ()
	{
		super.init ();
		java.util.Calendar c = java.util.Calendar.getInstance ();
		System.out.println (java.util.Calendar.SATURDAY);
		int day = c.get(java.util.Calendar.DAY_OF_WEEK), month = c.get(java.util.Calendar.MONTH), year = c.get(java.util.Calendar.YEAR);
		CalendarGrid cg = new CalendarGrid (day, month, year);
		add(cg);
	}

	@Override
	public void start ()
	{
		super.start ();
	}
}
