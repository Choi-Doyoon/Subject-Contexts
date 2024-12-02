package OOP.lecture17;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
public class MenuDemo extends JFrame implements ActionListener {
    MenuDemo() {
        System.setProperty("apple.laf.useScreenMenuBar", "false");
		setTitle("Menu Demo");
		makeMenu();
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setSize(300, 170);
		setVisible(true);
	}

	void makeMenu() {
		JMenuItem item;
		KeyStroke key;

		JMenuBar mb = new JMenuBar();
		JMenu m1 = new JMenu("File");
		m1.setMnemonic(KeyEvent.VK_F);
		JMenu m2 = new JMenu("Color");
		m2.setMnemonic(KeyEvent.VK_C);

		item = new JMenuItem("New", KeyEvent.VK_N);
		item.addActionListener(this);
		m1.add(item);
		item = new JMenuItem("Open", KeyEvent.VK_O);
		item.addActionListener(this);
		m1.add(item);
		m1.add(new JMenuItem("Save"));
		m1.addSeparator();
		m1.add(new JMenuItem("Exit"));

		item = new JMenuItem("Blue");
		key = KeyStroke.getKeyStroke(KeyEvent.VK_B, ActionEvent.CTRL_MASK);
		item.setAccelerator(key);
		item.addActionListener(this);
		m2.add(item);
		item = new JMenuItem("Red");
		key = KeyStroke.getKeyStroke(KeyEvent.VK_R, ActionEvent.CTRL_MASK);
		item.setAccelerator(key);
		item.addActionListener(this);
		m2.add(item);
		item = new JMenuItem("Yellow");
		key = KeyStroke.getKeyStroke(KeyEvent.VK_Y, ActionEvent.CTRL_MASK);
		item.setAccelerator(key);
		item.addActionListener(this);
		m2.add(item);
		mb.add(m1);
		mb.add(m2);
		setJMenuBar(mb);
	}

	public static void main(String[] args) {
		new MenuDemo();
	}

	public void actionPerformed(ActionEvent e) {
		JMenuItem mi = (JMenuItem) (e.getSource());

		switch (mi.getText()) {
		case "New":
			System.out.println("New");
			break;
		case "Open":
			System.out.println("Open");
			break;
		case "Blue":
			this.getContentPane().setBackground(Color.BLUE);
			break;
		case "Red":
			this.getContentPane().setBackground(Color.RED);
			break;
		case "Yellow":
			this.getContentPane().setBackground(Color.YELLOW);
		}
	}
}
