package OOP.lecture13;

import java.io.*;
import java.net.*;
import java.util.Scanner;

public class EchoClient {
    public static void main(String[] args) throws IOException{
        try{
            Socket client = new Socket();
            client.connect(new InetSocketAddress("www.google.com".9999),8888);
            PrintWriter out = new PrintWriter(client.getOutputStream(),true);

            Scanner in = new Scanner(System.in);
            String msg;
            System.out.print("Type: ");
            while((msg=in.nextLine()) != null){
                if(msg.contains("end"))
                break;
                out.println(msg);
            }

            out.close();
            in.close();
            client.close();
        } catch(Exception e){
            System.out.println(e);
        }
    }
}
