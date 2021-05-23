package practice_3;
import java.io.*;
import java.util.*;
 
public class out {
    public static void main(String[] args) {
	try {
	    String str = null;
	    FileReader input = new FileReader("in.txt");
	    BufferedReader in = new BufferedReader(input);
	    while((str = in.readLine())!=null) {
		 System.out.println(str);
	    }
	    in.close();
	    input.close();
	}
	catch(IOException e) {
	    System.out.println(e);
	}
    }
}
