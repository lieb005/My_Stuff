package pkg;

import java.awt.BorderLayout;
import java.awt.PopupMenu;
import java.awt.TrayIcon;

import javax.swing.ImageIcon;
import javax.swing.JApplet;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.UIManager;
import javax.swing.UIManager.LookAndFeelInfo;
import javax.swing.UnsupportedLookAndFeelException;

public class Calendar extends JApplet
{

	/**
	 * @param args
	 */
	public static void main (String[] args)
	{
		ImageIcon calendarIcon = new ImageIcon ("pkg/icon.png");
		TrayIcon trayIcon = new TrayIcon (calendarIcon.getImage ());
		trayIcon.setPopupMenu (new PopupMenu ("test"));
		JFrame f = new JFrame ("Calendar");
		Calendar c = new Calendar ();
		f.add (c);
		c.init ();
		c.start ();
		f.setVisible (true);
		c.repaint ();
		f.setSize (500, 500);
		f.setDefaultCloseOperation (JFrame.EXIT_ON_CLOSE);
		try
		{
			for (LookAndFeelInfo info : UIManager.getInstalledLookAndFeels ())
			{
				if ("Nimbus".equals (info.getName ()))
				{
					UIManager.setLookAndFeel (info.getClassName ());
					break;
				}
			}
		} catch (Exception e)
		{
			try
			{
				UIManager.setLookAndFeel (UIManager
						.getCrossPlatformLookAndFeelClassName ());
			} catch (ClassNotFoundException e1)
			{
				e1.printStackTrace ();
			} catch (InstantiationException e1)
			{
				e1.printStackTrace ();
			} catch (IllegalAccessException e1)
			{
				e1.printStackTrace ();
			} catch (UnsupportedLookAndFeelException e1)
			{
				e1.printStackTrace ();
			}
		}
	}

	@Override
	public void init ()
	{
		JPanel scrollButtonPane = new JPanel ();
		scrollButtonPane.setLayout (new BorderLayout ());
		DirectionButton fwd = new DirectionButton (true);
		DirectionButton bwd = new DirectionButton (false);
		scrollButtonPane.add (bwd, "West");
		scrollButtonPane.add (fwd, "East");
		add (scrollButtonPane);
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
