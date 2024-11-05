package OOP.lecture13.Socket;

import java.net.*; //네트워크 프로그래밍
import java.io.*; //I/O 스트림
//클라이언트를 위한 소켓 클래스
public class Whois {
    public static void main(String[] args) throws Exception{
        int c;
        Socket s= new Socket("whois.internic.net", 43); //소켓 클래스 생성자
        //I/O 스트림 접근 메서드
        InputStream in = s.getInputStream(); //소켓에서 InputStream 객체를 가져온다.(서버로부터 응답 읽기 담당)
        OutputStream out=s.getOutputStream(); //소켓에서 OutputStream 객체를 가져온다.(서버로 데이터를 보내는 담당)

        String str=(args.length == 0 ? "google.com" : args[0])+"\n";
        //args.length == 0이면 기본 도메인 "google.com"을 사용하고, 그렇지 않으면 명령줄 인수로 입력한 도메인을 사용합니다.
        byte[] buf=str.getBytes(); //str을 바이트 배열로 변환
        out.write(buf); //OutputStream을 통해 서버로 전송

        //서버 응답 읽기
        while((c=in.read()) != -1){
            //InputStream에서 서버의 응답을 1바이트씩 읽고, 이를 char로 변환해 출력.
            System.out.print((char) c);
        }
        s.close(); //소켓 닫기
    }
}
