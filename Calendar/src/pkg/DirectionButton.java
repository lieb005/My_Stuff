package pkg;

import javax.swing.JButton;

public class DirectionButton extends JButton
{
	public DirectionButton (boolean forward)
	{
		super (forward ? "→" : "←");
	}
}
