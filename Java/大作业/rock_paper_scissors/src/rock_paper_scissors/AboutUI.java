package rock_paper_scissors;

import java.awt.Color;
import java.awt.Desktop;
import java.awt.Font;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.awt.event.WindowListener;
import java.io.IOException;
import java.net.URI;
import java.net.URISyntaxException;

import javax.swing.JButton;
import javax.swing.JEditorPane;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextArea;

public class AboutUI {
	JFrame jf;
	JTextArea jta;
	JButton jb;

	public void init() {
		
		jf=new JFrame();
		jf.setTitle("关于");
		jf.setSize(300,300);
		jf.setResizable(false);
		
		jf.setLocationRelativeTo(null);
		jf.setLayout(null);

		jta =new JTextArea("        人机游戏：即可鼠标操作，又可按键操作(left代表PAPER，down代表SCISSORS，right代表ROCK);\n\n        人人游戏：甲玩家(A键代表PAPER，S键代表SCISSORS，D键代表ROCK)；乙玩家(left代表PAPER，down代表SCISSORS，right代表ROCK)",5,10);
		jta.setLineWrap(true);
		jta.setEditable(false);
		jf.add(jta);
		jta.setBounds(0, 0, 285, 250);
               
		jf.addWindowListener(new WindowListener() {
			
			@Override
			public void windowOpened(WindowEvent e) {
				// TODO 自动生成的方法存根
				
			}
			
			@Override
			public void windowIconified(WindowEvent e) {
				// TODO 自动生成的方法存根
				
			}
			
			@Override
			public void windowDeiconified(WindowEvent e) {
				// TODO 自动生成的方法存根
				
			}
			
			@Override
			public void windowDeactivated(WindowEvent e) {
				// TODO 自动生成的方法存根
				
			}
			
			@Override
			public void windowClosing(WindowEvent e) {
				// TODO 自动生成的方法存根
				AllFrames.mainUI.getJf().setEnabled(true);
			}
			
			@Override
			public void windowClosed(WindowEvent e) {
				// TODO 自动生成的方法存根
				
			}
			
			@Override
			public void windowActivated(WindowEvent e) {
				// TODO 自动生成的方法存根
				
			}
		});
		jf.setVisible(true);
	}

	public JFrame getJf() {
		return jf;
	}

	public void setJf(JFrame jf) {
		this.jf = jf;
	}
	

}
