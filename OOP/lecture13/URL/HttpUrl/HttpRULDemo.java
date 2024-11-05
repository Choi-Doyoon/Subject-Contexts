package OOP.lecture13.URL.HttpUrl;
import java.net.*;
import java.io.*;
import java.util.*;
public class HttpRULDemo {
    public static void main(String[] args) throws IOException{
        URL hp = new URL("http://www.google.com");
        HttpURLConnection hpCon = (HttpURLConnection) hp.openConnection(); //HttpURLConnection 객체 생성
        System.out.println("Request method is "+hpCon.getRequestMethod()); //HTTP 요청 메서드
        System.out.println("Response code is "+hpCon.getResponseCode()); //HTTP 응답 코드
        System.out.println("Response Message is "+hpCon.getResponseMessage()); //HTTP 응답 메시지

        Map<String, List<String>> hdrMap=hpCon.getHeaderFields(); //모든 HTTP 헤더 필드의 키,값
        Set<String> hdrField = hdrMap.keySet(); 

        System.out.println("\nHere is the header:");
        for(String k: hdrField){
            System.out.println("Key: "+k+"  Value: "+hdrMap.get(k));
        }
    }
}
