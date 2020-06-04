package rock_paper_scissors;

import java.awt.Color;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.awt.event.WindowListener;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;

import javax.swing.JOptionPane;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextArea;

public class GameUI {
    JFrame jf;
    JButton jb, jb1, jb2, jb3;
    JTextArea jta;
    int returnNUM = 0;

    // static int NUM;
    public void init(int num) {
        jf = new JFrame();

        //jp.setSize(200+8+8, 200+31+8);
        jf.setTitle("正在游戏");
        jf.setSize(217 + 8 + 8, 250 + 31 + 8);
        jf.setResizable(false);
        jf.setLocationRelativeTo(null);
        jf.setLayout(null);
        for (int i = 1; i <= 3; i++) {
            jb = new JButton();
            final int j = i;
            jb.addActionListener(new ActionListener() {
                @Override
                public void actionPerformed(ActionEvent e) {
                    // TODO 自动生成的方法存根
                    jb1.setIcon(new ImageIcon(getClass().getResource(j + ".png")));
                    returnNUM = AI.ai(j);
                    jb2.setIcon(new ImageIcon("src\\rock_paper_scissors\\" + returnNUM + ".png"));

                    jta.setText("赢：" + AI.winNUM + "次     平：" + AI.drawNUM + "次      输：" + AI.lostNUM + "次");
                    jf.repaint();


                    if (AI.winNUM == num / 2 + 1) {
                        int res = JOptionPane.showConfirmDialog(null, "恭喜您赢了！！！\n是否继续操作", "是否继续", JOptionPane.YES_NO_OPTION);
                        if (res == JOptionPane.YES_OPTION) {
                            //System.out.println("选择是后执行的代码"); // 点击“是”后执行这个代码块
                            AI.winNUM = AI.drawNUM = AI.lostNUM = 0;

                        } else {
                            //System.out.println("选择否后执行的代码"); // 点击“否”后执行这个代码块
                            //return;
                            AllFrames.mainUI.getJf().setVisible(true);
                            closeAction();
                            jf.dispose();
                        }
                    } else if (AI.lostNUM == num / 2 + 1 ) {
                        int res = JOptionPane.showConfirmDialog(null, "遗憾您输了。。。\n是否继续操作", "是否继续", JOptionPane.YES_NO_OPTION);
                        if (res == JOptionPane.YES_OPTION) {
                            //System.out.println("选择是后执行的代码"); // 点击“是”后执行这个代码块
                            AI.winNUM = AI.drawNUM = AI.lostNUM = 0;


                        } else {
                            //System.out.println("选择否后执行的代码"); // 点击“否”后执行这个代码块
                            //return;
                            AllFrames.mainUI.getJf().setVisible(true);
                            closeAction();
                            jf.dispose();
                        }
                    }
                }

            });

            jb.addKeyListener(new KeyAdapter() {
                public void keyPressed(KeyEvent e) {
                    if (e.getKeyCode() == KeyEvent.VK_LEFT) {
                        jb1.setIcon(new ImageIcon(getClass().getResource(1 + ".png")));
                        returnNUM = AI.ai(1);
                    } else if (e.getKeyCode() == KeyEvent.VK_DOWN) {
                        jb1.setIcon(new ImageIcon(getClass().getResource(2 + ".png")));
                        returnNUM = AI.ai(2);
                    } else if (e.getKeyCode() == KeyEvent.VK_RIGHT) {
                        jb1.setIcon(new ImageIcon(getClass().getResource(3 + ".png")));
                        returnNUM = AI.ai(3);
                    }

                    jb2.setIcon(new ImageIcon("src\\rock_paper_scissors\\" + returnNUM + ".png"));
                    jta.setText("赢：" + AI.winNUM + "次     平：" + AI.drawNUM + "次      输：" + AI.lostNUM + "次");
                    jf.repaint();

                    if (AI.winNUM == num / 2 + 1 && AI.lostNUM <= num / 2) {
                        int res = JOptionPane.showConfirmDialog(null, "恭喜您赢了！！！\n是否继续操作", "是否继续", JOptionPane.YES_NO_OPTION);
                        if (res == JOptionPane.YES_OPTION) {
                            //System.out.println("选择是后执行的代码"); // 点击“是”后执行这个代码块
                            AI.winNUM = AI.drawNUM = AI.lostNUM = 0;

                        } else {
                            //System.out.println("选择否后执行的代码"); // 点击“否”后执行这个代码块
                            //return;
                            AllFrames.mainUI.getJf().setVisible(true);
                            closeAction();
                            jf.dispose();
                        }
                    } else if (AI.lostNUM == num / 2 + 1 && AI.winNUM <= num / 2) {
                        int res = JOptionPane.showConfirmDialog(null, "遗憾您输了。。。\n是否继续操作", "是否继续", JOptionPane.YES_NO_OPTION);
                        if (res == JOptionPane.YES_OPTION) {
                            //System.out.println("选择是后执行的代码"); // 点击“是”后执行这个代码块
                            AI.winNUM = AI.drawNUM = AI.lostNUM = 0;


                        } else {
                            //System.out.println("选择否后执行的代码"); // 点击“否”后执行这个代码块
                            //return;
                            AllFrames.mainUI.getJf().setVisible(true);
                            closeAction();
                            jf.dispose();
                        }
                    }
               
                }
            });

            jb.setBorderPainted(false);//不打印边框
            jb.setBorder(null);//除去边框
            jb.setFocusPainted(false);//除去焦点的框
            jb.setContentAreaFilled(false);
            jb.setIcon(new ImageIcon(getClass().getResource(i + ".png")));
            jf.add(jb);
            jb.setBounds(0, (i - 1) * 65, 73, 65);
        }

        jb1 = new JButton();
        jb1.setBorderPainted(false);//不打印边框
        jb1.setBorder(null);//除去边框
        jb1.setFocusPainted(false);//除去焦点的框
        jb1.setContentAreaFilled(false);
        //jb1.setIcon(new ImageIcon());
        jf.add(jb1);
        jb1.setBounds(73, 65, 73, 65);

        jb2 = new JButton();//ai猜拳
        jb2.setBorderPainted(false);//不打印边框
        jb2.setBorder(null);//除去边框
        jb2.setFocusPainted(false);//除去焦点的框
        jb2.setContentAreaFilled(false);
        jf.add(jb2);
        jb2.setBounds(145, 65, 73, 65);


        jb3 = new JButton("结束游戏");
        jb3.setBorderPainted(false);
        jb3.setBorder(null);
        jb3.setFocusable(false);
        jb3.setContentAreaFilled(false);
        jb3.setFont(new Font("华文行楷", Font.BOLD, 20));
        jb3.addMouseListener(new MouseAdapter() {


            @Override
            public void mouseExited(MouseEvent e) {
                // TODO 自动生成的方法存根
                jb3.setForeground(Color.black);
            }

            @Override
            public void mouseEntered(MouseEvent e) {
                // TODO 自动生成的方法存根
                jb3.setForeground(Color.blue);
            }

            @Override
            public void mouseClicked(MouseEvent e) {
                // TODO 自动生成的方法存根
                AllFrames.mainUI.getJf().setVisible(true);
                closeAction();
                jf.dispose();
            }
        });
        jf.add(jb3);
        jb3.setBounds(60, 200, 100, 40);

        jta = new JTextArea("赢：  平： 输： ");
        jta.setLineWrap(true);
        jta.setEditable(false);
        jf.add(jta);
        jta.setBounds(73, 0, 140, 65);

        jf.addWindowListener(new WindowAdapter() {

            @Override
            public void windowClosing(WindowEvent e) {
                // TODO 自动生成的方法存根
                AllFrames.mainUI.getJf().setVisible(true);
                closeAction();
                jf.dispose();
            }

        });
        jf.setVisible(true);
    }

    public void closeAction() {
        AI.drawNUM = AI.lostNUM = AI.winNUM = 0;

    }
}
