package OOP.lecture13.URL;
import java.net.*;
public class URLDemo {
    public static void main(String[] args) throws MalformedURLException{
        URL hp = new URL("https://cs.kw.ac.kr:501/main/main.php"); //URL 클래스 생성자

        System.out.println("Protocol: "+hp.getProtocol()); //프로토콜
        System.out.println("Port: " + hp.getPort()); //포트 번호
        System.out.println("Host: "+hp.getHost()); //호스트 이름
        System.out.println("File: "+hp.getFile()); //파일 경로(이름)
        System.out.println("Ext:"+hp.toExternalForm()); //URL 객체가 표현하는 URL을 문자열로 반환
    }
}
