/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package rmbtodollar;

/**
 *
 * @author anfen
 */


import java.awt.Color;
import java.awt.FlowLayout;
import java.awt.Frame;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.math.BigDecimal;
 
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class RMBtoDollar {
    public static void main(String[] args) {
        // TODO code application logic here
        new MyFrame2("汇率转换").Run();
    }    
}


class MyFrame2 extends Frame{
    private static final long serialVersionUID = 1L;

    public MyFrame2(String s) {
            super(s);
    }

    public void Run(){
    JPanel jp=new JPanel();
    JLabel  label1=new JLabel("人民币");
    JTextField rmb=new JTextField(10);	
    JButton button=new JButton("汇率转换为");
    JTextField my=new JTextField(10);
    my.setEnabled(false);//设置美元文本框只读属性
    JLabel label2=new JLabel("美元");
    this.setBackground(Color.GRAY);
    this.add(jp);
    jp.setLayout(new FlowLayout());
    jp.add(label1);
    jp.add(rmb);
    jp.add(button);
    jp.add(my);
    jp.add(label2);
    button.setActionCommand("rmb");
    this.setSize(300, 300);
    this.setLocation(500, 300);
    this.setVisible(true);
    //事件监听，关闭窗口
    this.addWindowListener(new WindowAdapter(){
            public void windowClosing(WindowEvent e) {
                    System.exit(0);
            }

    });
    //事件监听，汇率转换
    button.addActionListener(new ActionListener(){
         public void actionPerformed(ActionEvent e) {
             String s1 = rmb.getText();
             double rmbnumber = Double.parseDouble(s1);
             double mynumber = rmbnumber * 100.00 / 688.00;
             BigDecimal b = new BigDecimal(mynumber);
             double ans = b.setScale(2, BigDecimal.ROUND_HALF_UP).doubleValue();
             String s2 = String.valueOf(ans);
             my.setText(s2);
         }	
     });	
    }
}