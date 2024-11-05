package OOP.lecture13.HttpClient;
import java.net.*;
import java.net.http.*;
import java.io.*;
import java.util.*;
public class HttpClientDemo {
    public static void main(String[] args) throws Exception{
        HttpClient myHC= HttpClient.newHttpClient(); //HttpClient 객체 생성
        HttpRequest myReq = HttpRequest.newBuilder(new URI("http://www.google.com/")).build(); //HttpRequest 객체 생성
        //http://www.google.com/ URL에 GET 요청을 보내도록 설정
        HttpResponse<InputStream> myResp = myHC.send(myReq,HttpResponse.BodyHandlers.ofInputStream()); //HttpResponse 객체로 수신
        //myHC.send() 메서드를 호출하여 요청을 보내고 응답을 수신. 응답은 InputStream으로 처리.
        System.out.println("Response code is "+myResp.statusCode()); //응답의 상태 코드 출력
        System.out.println("Request method is "+myReq.method()); //요청 메서드를 출력
        HttpHeaders hdrs = myResp.headers(); //응답의 헤더 생성

        Map<String, List<String>> hdrMap = hdrs.map(); //헤더를 Map으로 변환
        Set<String> hdrField = hdrMap.keySet();
        System.out.println("\nHere is the header:");
        for(String k: hdrField){ //각 헤더 필드와 값을 출력함.
            System.out.println("Key: "+k+"  Value: "+hdrMap.get(k));
        }
        System.out.println("\nHere is the body: ");
        InputStream input = myResp.body();
        int c;

        //Read and display the entire body.
        
        while((c=input.read())!=-1){
            System.out.print((char) c);
        }
        
    }
}
