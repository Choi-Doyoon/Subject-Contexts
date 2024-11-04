import java.io.*; // I/O 스트림 패키지의 클래스

public class BRRead{
    public static void main(String[] args) throws IOException{ //입출력에서 발생할 수 있는 IOException을 호출하는 곳으로 전달
        char c;
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in,System.console().charset())); //BufferedReader 객체 생성
        //BufferedReader는 입력을 버퍼링하여 효율적 처리 가능(바이트 스트림)
        //System.in은 표준 입력 스트림.
        //InputStreamReader는 바이트 스트림->문자 스트림 변환
        System.out.println("Enter characters, 'q' to quit.");
        do{
            c=(char) br.read(); //BufferedReader에 입력된 문자 읽음
            //입력된 문자의 유니코드 값 리턴
            //스트림이 끝나면 -1 리턴
            System.out.println(c);
        } while(c!='q');
    }
}