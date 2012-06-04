package pkg;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JApplet;
import javax.swing.JFrame;
import javax.swing.JScrollPane;
import javax.swing.UIManager;
import javax.swing.UIManager.LookAndFeelInfo;
import javax.swing.UnsupportedLookAndFeelException;

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
		c.init ();
		c.start ();
		f.setVisible (true);
		c.repaint ();
		f.setSize (500, 500);
		f.setDefaultCloseOperation (JFrame.EXIT_ON_CLOSE);
		try {
		    for (LookAndFeelInfo info : UIManager.getInstalledLookAndFeels()) {
		        if ("Nimbus".equals(info.getName())) {
		            UIManager.setLookAndFeel(info.getClassName());
		            break;
		        }
		    }
		} catch (Exception e) {
			try
			{
				UIManager.setLookAndFeel (UIManager.getCrossPlatformLookAndFeelClassName ());
			} catch (ClassNotFoundException e1)
			{
				e1.printStackTrace();
			} catch (InstantiationException e1)
			{
				e1.printStackTrace();
			} catch (IllegalAccessException e1)
			{
				e1.printStackTrace();
			} catch (UnsupportedLookAndFeelException e1)
			{
				e1.printStackTrace();
			}
		}
	}

	@Override
	public void init ()
	{
		super.init ();
		java.util.Calendar c = java.util.Calendar.getInstance ();
		int month = c.get (java.util.Calendar.MONTH), year = c
				.get (java.util.Calendar.YEAR);
		CalendarGrid cg = new CalendarGrid (month, year);
		add (new JScrollPane (cg));
	}

	@Override
	public void start ()
	{
		super.start ();
	}
}
