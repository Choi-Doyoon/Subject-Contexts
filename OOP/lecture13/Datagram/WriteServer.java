package OOP.lecture13.Datagram;
import java.net.*;
public class WriteServer {
    public static int serverPort = 1099;
    public static int clientPort = 1098;
    public static int buffer_size=1024;
    public static DatagramSocket ds;
    public static byte[] buffer = new byte[buffer_size];

    public static void TheServer() throws Exception{
        int pos=0;

        while(true){
            int c=System.in.read();
            switch(c){
                case 'q':
                    System.out.println("Server Quits.");
                    ds.close();
                    return;
                case '\r':
                    break;
                case '\n':
                    ds.send(new DatagramPacket(buffer, pos, InetAddress.getByName("127.0.0.1"), clientPort));
                    pos=0;
                    break;
                default:
                    buffer[pos++] = (byte) c;
            }
        }
    }

    public static void TheClient() throws Exception{
        while(true){
            DatagramPacket p = new DatagramPacket(buffer, buffer.length);
            ds.receive(p);
            System.out.println(new String(p.getData(),0,p.getLength()));
        }
    }

    public static void main(String[] args) throws Exception{
        if(args.length == 1){
            ds = new DatagramSocket(serverPort);
            ds.setReuseAddress(true);
            TheServer();
        }
        else{
            ds=new DatagramSocket(clientPort);
            ds.setReuseAddress(true);
            TheClient();
        }
    }
}
