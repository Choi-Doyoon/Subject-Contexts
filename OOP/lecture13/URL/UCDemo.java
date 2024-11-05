package OOP.lecture13.URL;
import java.net.*;
import java.io.*;
import java.util.Date;
public class UCDemo {
    public static void main(String[] args) throws IOException{
        //int c;
        URL hp = new URL("http://www.google.com");
        URLConnection hpCon = hp.openConnection(); //URLConnection 객체 생성

        System.out.println("Date: "+new Date(hpCon.getDate())); //HTTP 응답 메시지가 반환된 일시
        System.out.println("Content-Type: "+hpCon.getContentType()); //HTTP 페이로드 타입
        System.out.println("Expires: "+new Date(hpCon.getExpiration())); //HTTP 응답 메시지가 유효한 일시
        System.out.println("Last-Modified: "+new Date(hpCon.getLastModified())); //자원이 마지막으로 수정된 시간
        long len=hpCon.getContentLengthLong(); //HTTP 헤더 중 ContentLength
        System.out.println("Content-Length: "+len);
        /*if(len !=0){
            System.out.println("=== Content ===");
            InputStream input = hpCon.getInputStream();

            while(((c=input.read())!=-1)){
                System.out.println((char) c);
            }
            input.close();
        }
        else{
            System.out.println("No content available.");
        }*/
    }
}
