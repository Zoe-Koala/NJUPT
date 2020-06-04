package rock_paper_scissors;

import java.awt.Font;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

import javax.swing.JButton;
import javax.swing.JFrame;

public class ChooseUI {
    JFrame jf;
    JButton jb1, jb2, jb3, jb4;
    MyPanel jp;

    public void init(Type type,String path) {//初始化
        jf = new JFrame();//东西南北中，五个位置。
        jp = new MyPanel();
        if (path == null) {
            MyPanel.path = "src\\rock_paper_scissors\\背景0.jpg";
        } else {
            MyPanel.path = path;
        }
        //jp.setOpaque(false);将jpanel设置为透明将显示jfreame的背景颜色
        jp.setSize(400 + 8 + 8, 400 + 31 + 8);
        jf.setTitle("模式选择");
        jf.setSize(400 + 8 + 8, 400 + 31);
        jf.setResizable(false);//设置此窗体是否可由用户调整大小。
        jf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        jf.setLocationRelativeTo(null);
        jf.setLayout(null);
        jp.setLayout(null);//jpanel为流式布局改为空

        Map<Integer,JButton> jButtonMap = new HashMap<>();//key存储init的参数
        jb1 = new JButton("一局胜负");
        jb2 = new JButton("三局两胜");
        jb3 = new JButton("五局三胜");
        jb4 = new JButton("无尽之战");

        jButtonMap.put(1,jb1);
        jButtonMap.put(3,jb2);
        jButtonMap.put(5,jb3);
        jButtonMap.put(10000,jb4);
        for(Map.Entry<Integer,JButton> entry : jButtonMap.entrySet()){
            entry.getValue().setFont(new Font("华文行楷", Font.BOLD, 30));
            //	jb1.setSize(100, 50);
            entry.getValue().setBorderPainted(false);//不打印边框
            entry.getValue().setBorder(null);//除去边框
            entry.getValue().setFocusPainted(false);//除去焦点的框
            entry.getValue().setContentAreaFilled(false);
            entry.getValue().addMouseListener(new MouseAdapter() {

                @Override
                public void mouseExited(MouseEvent e) {
                    // TODO 自动生成的方法存根
                    entry.getValue().setFont(new Font("华文行楷", Font.BOLD, 30));
                }

                @Override
                public void mouseEntered(MouseEvent e) {
                    // TODO 自动生成的方法存根
                    //entry.getValue().setBounds(115, 50, 170, 50);
                    entry.getValue().setFont(new Font("华文行楷", Font.BOLD, 40));

                }

                @Override
                public void mouseClicked(MouseEvent e) {
                    // TODO 自动生成的方法存根
                    jf.setVisible(false);
                    //AllFrames.mainUI.getJf().setVisible(false);
                    if(type == Type.MAN_MACHINE){
                        GameUI gameUI = new GameUI();
                        gameUI.init(entry.getKey());
                    }else if(type == Type.MAN_MAN){
                        HumanUI humanUI = new HumanUI();
                        humanUI.init(entry.getKey());
                        AllFrames.humanUI = humanUI;
                    }
                }
            });
        }

        jp.add(jb1);
        jb1.setBounds(125, 50, 170, 50);
        jp.add(jb2);
        jb2.setBounds(125, 150, 170, 50);
        jp.add(jb3);
        jb3.setBounds(125, 250, 170, 50);
        jp.add(jb4);
        jb4.setBounds(125, 350, 170, 50);

        jf.add(jp);
        jf.setVisible(true);//方法的意思是说数据模型已经构造好了，允许JVM可以根据数据模型执行paint方法开始画图并显示到屏幕上了，并不是显示图形，而是可以运行开始画图了。
        jf.repaint();
    }

    public JFrame getJf() {
        return jf;
    }

    public void setJf(JFrame jf) {
        this.jf = jf;
    }

}
