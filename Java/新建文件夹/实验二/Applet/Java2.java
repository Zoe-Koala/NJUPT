
import java.applet.*;
import java.awt.*;
import java.awt.event.*;
public class Java2 extends Applet implements ActionListener
{
    Button b,c;
    public void init()
    {
        Label label=new Label("请按按钮：");
        b=new Button("按钮1");//构造按钮
        b.addActionListener(this);//监视器
        c=new Button("按钮2");
        c.addActionListener(this);
        add(label);
        add(b);//将按钮加入网页
        add(c);
    }
    public void actionPerformed(ActionEvent e)
    {
        if(e.getSource()==b)
        {
            Frame frame=new Frame("提醒");
            frame.setSize(230,100);//设置大小
            frame.setLocation(100,100);//设置位置
            frame.add(new Label("你按了按钮1"));//添加标签
            frame.setVisible(true);//设置是否可见
            frame.validate();
        }
        else if(e.getSource()==c)
        {
            Frame frame=new Frame("提醒");
            frame.setSize(230,100);
            frame.setLocation(100,100);
            frame.add(new Label("你按了按钮2"));
            frame.setVisible(true);
            frame.validate();
        }
    }
}
