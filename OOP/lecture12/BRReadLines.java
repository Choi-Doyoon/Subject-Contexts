import java.io.*;

public class BRReadLines{
    public static void main(String[] args) throws IOException{
        //create a BufferedReader using System.in
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in,System.console().charset()));

        String str;
        System.out.println("Enter 'stop' to quit.");
        do{
            str=br.readLine(); //입력된 문자열을 한 줄 읽음(String return)
            System.out.println(str);
        } while (!str.equals("stop"));
    }
}