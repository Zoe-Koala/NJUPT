package practice_3;
import java.io.*;
import java.util.*;
 
public class in {
    File file = new File("in.txt");  //新建文件
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        try {
             System.out.println("请输入：");
             String str = input.nextLine();
            FileWriter output = new FileWriter("in.txt");
            BufferedWriter out = new BufferedWriter(output);
            out.write(str);
            out.newLine();
            out.close();
            out.close();
         }
        catch(IOException e){
            System.out.println(e);
         }
    }
}
