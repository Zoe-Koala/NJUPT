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
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.KeyAdapter;
import javax.swing.*;

public class HumanUI {
    JPanel jPanel;
    JFrame jf;
    JButton jb, jb1, jb2, jb3;
    JTextArea jta1, jta2;
    int winNUM = 0;
    int drawNUM = 0;
    int lostNUM = 0;
    Clock clock;
    Select left;
    Select right;
    boolean leftLock = false;//锁，如果已经有了数字，就给上锁
    boolean rightLock = false;
    int returnNUM = 0;

    public void init(int num) {
        jf = new JFrame();
        jPanel = new JPanel();
        jPanel.setLayout(null);
        jPanel.setSize(306, 250 + 31 + 8);
        
        jf.getContentPane().add(jPanel);
        //jp.setSize(200+8+8, 200+31+8);
        jf.setTitle("正在游戏");
        jf.setSize(306, 250 + 31 + 8);
        jf.setResizable(false);
        jf.setLocationRelativeTo(null);
        jf.setLayout(null);

        jb1 = new JButton();//human1猜拳
        jb1.setBorderPainted(false);//不打印边框
        jb1.setBorder(null);//除去边框
        jb1.setFocusPainted(false);//除去焦点的框
        jb1.setContentAreaFilled(false);
        //jb1.setIcon(new ImageIcon());
        jPanel.add(jb1);
        jb1.setBounds(73, 65, 73, 65);

        jb2 = new JButton();//human2猜拳
        jb2.setBorderPainted(false);//不打印边框
        jb2.setBorder(null);//除去边框
        jb2.setFocusPainted(false);//除去焦点的框
        jb2.setContentAreaFilled(false);
        jPanel.add(jb2);
        jb2.setBounds(145, 65, 73, 65);

        for (int i = 1; i <= 3; i++) {
            jb = new JButton();
            jb.addKeyListener(new KeyAdapter() {
                public void keyPressed(KeyEvent e) {
                    if (leftLock) {//如果上锁了，直接返回
                        ;
                    } else if (e.getKeyCode() == KeyEvent.VK_A) {
                        jb1.setIcon(new ImageIcon(getClass().getResource(4 + ".png")));
                        left = Select.PAPER;
                        returnNUM = AI.ai(1);
                        leftLock = true;
                        if(clock==null){
                            clock = new Clock(Clock.RIGHT);
                        }
                    } else if (e.getKeyCode() == KeyEvent.VK_S) {
                        jb1.setIcon(new ImageIcon(getClass().getResource(4 + ".png")));
                        left = Select.SCISSORS;
                        returnNUM = AI.ai(2);
                        leftLock = true;
                        if(clock==null){
                            clock = new Clock(Clock.RIGHT);
                        }
                    } else if (e.getKeyCode() == KeyEvent.VK_D) {
                        jb1.setIcon(new ImageIcon(getClass().getResource(4 + ".png")));
                        left = Select.ROCK;
                        returnNUM = AI.ai(3);
                        leftLock = true;
                        if(clock==null){
                            clock = new Clock(Clock.RIGHT);
                        }
                    }
                    if (rightLock) {//如果上锁了，直接返回
                       ;
                    } else if (e.getKeyCode() == KeyEvent.VK_LEFT) {
                        jb2.setIcon(new ImageIcon(getClass().getResource(5 + ".png")));
                        right = Select.PAPER;
                        returnNUM = AI.ai(1);
                        rightLock = true;
                        if(clock==null){
                            clock = new Clock(Clock.LEFT);
                        }
                    } else if (e.getKeyCode() == KeyEvent.VK_DOWN) {
                        jb2.setIcon(new ImageIcon(getClass().getResource(5 + ".png")));
                        right = Select.SCISSORS;
                        returnNUM = AI.ai(2);
                        rightLock = true;
                        if(clock==null){
                            clock = new Clock(Clock.LEFT);
                        }
                    } else if (e.getKeyCode() == KeyEvent.VK_RIGHT) {
                        jb2.setIcon(new ImageIcon(getClass().getResource(5 + ".png")));
                        right = Select.ROCK;
                        returnNUM = AI.ai(3);
                        rightLock = true;
                        if(clock==null){
                            clock = new Clock(Clock.LEFT);
                        }
                    }
                    if (operate()) {
                        leftLock = rightLock = false;//解锁
                        jta1.setText("甲：赢：" + winNUM + "次     平：" + drawNUM + "次      输：" + lostNUM + "次");
                        jta2.setText("乙：赢：" + lostNUM + "次     平：" + drawNUM + "次      输：" + winNUM + "次");
                    }
                    jf.repaint();
                    
                    

                    if (winNUM==num/2+1 ) {
                        int res = JOptionPane.showConfirmDialog(null, "恭喜甲赢了！！！\n是否继续操作", "是否继续", JOptionPane.YES_NO_OPTION);
                        if (res == JOptionPane.YES_OPTION) {
                            //System.out.println("选择是后执行的代码"); // 点击“是”后执行这个代码块
                            winNUM = drawNUM = lostNUM = 0;


                        } else {
                            //System.out.println("选择否后执行的代码"); // 点击“否”后执行这个代码块
                            //return;
                            AllFrames.mainUI.getJf().setVisible(true);
                            closeAction();
                            jf.dispose();
                        }
                    } else if (lostNUM==num/2+1 ) {
                        int res = JOptionPane.showConfirmDialog(null, "恭喜乙赢了！！！\n是否继续操作", "是否继续", JOptionPane.YES_NO_OPTION);
                        if (res == JOptionPane.YES_OPTION) {
                            //System.out.println("选择是后执行的代码"); // 点击“是”后执行这个代码块
                            winNUM = drawNUM = lostNUM = 0;


                        } else {
                            //System.out.println("选择否后执行的代码"); // 点击“否”后执行这个代码块
                            //return;
                            AllFrames.mainUI.getJf().setVisible(true);
                            closeAction();
                            jf.dispose();
                        }
                    }
//                    else if (drawNUM==1 && num==1) {
//                        int res = JOptionPane.showConfirmDialog(null, "好巧，平局嗷~\n是否继续操作", "是否继续", JOptionPane.YES_NO_OPTION);
//                        if (res == JOptionPane.YES_OPTION) {
//                            //System.out.println("选择是后执行的代码"); // 点击“是”后执行这个代码块
//                            winNUM = drawNUM = lostNUM = 0;
//
//
//                        } else {
//                            //System.out.println("选择否后执行的代码"); // 点击“否”后执行这个代码块
//                            //return;
//                            AllFrames.mainUI.getJf().setVisible(true);
//                            closeAction();
//                            jf.dispose();
//                        }
//                    }
                }                    


            });

            jb.setBorderPainted(false);//不打印边框
            jb.setBorder(null);//除去边框
            jb.setFocusPainted(false);//除去焦点的框
            jb.setContentAreaFilled(false);
            jb.setIcon(new ImageIcon(getClass().getResource(i + ".png")));
            jPanel.add(jb);
            jb.setBounds(0, (i - 1) * 65, 73, 65);
        }

        for (int i = 1; i <= 3; i++) {
            jb = new JButton();
            jb.setBorderPainted(false);//不打印边框
            jb.setBorder(null);//除去边框
            jb.setFocusPainted(false);//除去焦点的框
            jb.setContentAreaFilled(false);
            jb.setIcon(new ImageIcon(getClass().getResource(i + ".png")));
            jPanel.add(jb);
            jb.setBounds(219, (i - 1) * 65, 73, 65);
        }

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
        jPanel.add(jb3);
        jb3.setBounds(96, 200, 100, 40);

        jta1 = new JTextArea("甲：赢：  平： 输： ");
        jta1.setLineWrap(true);
        jta1.setEditable(false);
        jPanel.add(jta1);
        jta1.setBounds(73, 0, 145, 65);

        jta2 = new JTextArea("乙：赢：  平： 输： ");
        jta2.setLineWrap(true);
        jta2.setEditable(false);
        jPanel.add(jta2);
        jta2.setBounds(73, 130, 145, 65);

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

    //当两边都输入时，试图计算结果.返回true说明计算成功了
    public boolean operate() {
        if (leftLock && rightLock) {
            clock.setVisible(false);
            clock = null;
            Result r = Tool.judge(left, right);
            switch (r) {
                case LEFT_WIN:
                    winNUM++;
                    break;
                case RIGHT_WIN:
                    lostNUM++;
                    break;
                case ALL_WIN:
                    drawNUM++;
            }
            switch (left) {
                case ROCK:
                    jb1.setIcon(new ImageIcon(getClass().getResource(3 + ".png")));
                    break;
                case SCISSORS:
                    jb1.setIcon(new ImageIcon(getClass().getResource(2 + ".png")));
                    break;
                case PAPER:
                    jb1.setIcon(new ImageIcon(getClass().getResource(1 + ".png")));
                    break;
            }
            switch (right) {
                case ROCK:
                    jb2.setIcon(new ImageIcon(getClass().getResource(3 + ".png")));
                    break;
                case SCISSORS:
                    jb2.setIcon(new ImageIcon(getClass().getResource(2 + ".png")));
                    break;
                case PAPER:
                    jb2.setIcon(new ImageIcon(getClass().getResource(1 + ".png")));
                    break;
            }
            return true;
        }else if(leftLock){
            jPanel.add(clock);
        }else if(rightLock){
            jPanel.add(clock);
        }
        return false;
    }
    public void reStart(){
        winNUM = lostNUM = drawNUM = 0;
        leftLock = rightLock = false;
        jb1.setIcon(null);
        jb2.setIcon(null);
        clock = null;
    }

}
