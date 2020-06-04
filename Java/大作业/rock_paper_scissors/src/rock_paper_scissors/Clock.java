package rock_paper_scissors;

import javax.swing.*;
import java.awt.*;

//倒计时
public class Clock extends JPanel implements Runnable {
    private int num;//到达0秒时判负
    //static int i = 1;
    public final static int LEFT = 0;//左边的倒计时
    public final static int RIGHT = 1;//右边的倒计时
    private Thread thread;
    private int position;
    private JLabel jLabel;
    private boolean isStop;

    public Clock(int where) {
        this.num = 3;
        position = where;
        this.jLabel = new JLabel("还有" + num + "秒！");
        jLabel.setForeground(Color.RED);
        if(where == LEFT){
            this.setBounds(22, 200, 100, 40);
        }else{
            this.setBounds(188, 200, 100, 40);
        }
        //System.out.println("?"+i++);
        this.add(jLabel);
        thread = new Thread(this);
        isStop = false;
        thread.start();
    }

    @Override
    public void run() {
        while (!isStop){
            try{
                Thread.sleep(1000);
            }catch (Exception e){
                e.printStackTrace();
            }
            num--;
            jLabel.setText("还有" + num + "秒！");
            if(num == 0 && this.isVisible()){
                String message = "";
                if (position == LEFT) {
                    message = "乙";
                } else if(position == RIGHT){
                    message = "甲";
                }
                int res = JOptionPane.showConfirmDialog(null, "恭喜"+message+"赢了！！！\n是否继续操作", "是否继续", JOptionPane.YES_NO_OPTION);
                if (res == JOptionPane.YES_OPTION) {
                    //System.out.println("选择是后执行的代码"); // 点击“是”后执行这个代码块
                    AllFrames.humanUI.reStart();

                } else {
                    //System.out.println("选择否后执行的代码"); // 点击“否”后执行这个代码块
                    //return;
                    AllFrames.mainUI.getJf().setVisible(true);
                    AllFrames.humanUI.closeAction();
                    AllFrames.humanUI.jf.dispose();
                }
                stop();
            }
        }
    }

    public void stop(){
        isStop = true;
        this.setVisible(false);
        thread = null;
    }
}
