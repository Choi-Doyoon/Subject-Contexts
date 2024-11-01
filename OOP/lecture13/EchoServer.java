package OOP.lecture13;

import java.io.*;
import java.net.*;

public class EchoServer {
    public static void main(String[] args) throws IOException{
        ServerSocket server = new ServerSocket(9999);
        server.setReuseAddress(true);

        Socket connection = server.accept(); //클라이언트의 연결 요청을 받아 Socket 객체 생성
        BufferedReader in = new BufferedReader(new InputStreamReader(connection.getInputStream()));

        String msg = null;

        while((msg = in.readLine()) != null){
            if(msg.contains("end"))
                break;
                System.out.println("Received: "+msg);
        }
        in.close();
        connection.close();
        server.close();
    }
}