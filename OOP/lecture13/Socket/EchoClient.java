package OOP.lecture13.Socket;

import java.io.*;
import java.net.*;
import java.util.Scanner;

public class EchoClient {
    public static void main(String[] args) throws IOException{
        try{
            Socket client = new Socket();
            client.connect(new InetSocketAddress("localhost",9999),8888);
            //클라이언트가 서버에 연결을 시도할 때 사용하는 메서드(connect 메서드)
            PrintWriter out=new PrintWriter(client.getOutputStream(),true);
            Scanner in = new Scanner(System.in);
            String msg;

            System.out.print("Type: ");
                while((msg=in.nextLine())!=null){
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
