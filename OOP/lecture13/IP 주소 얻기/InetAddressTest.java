package OOP.lecture13;
import java.net.*; //네트워크 프로그래밍 기본 제공 패키지
public class InetAddressTest{
    public static void main(String[] args) throws UnknownHostException{ //호스트 관련 오류 예외처리
        InetAddress Address=InetAddress.getLocalHost(); //로컬 호스트 이름과 IP 주소를 출력합니다. (예: 컴퓨터이름/192.168.1.10)
        System.out.println(Address); //로컬 IP 주소 출력(컴퓨터 이름/로컬 IP 주소)
        Address=InetAddress.getByName("www.google.com"); //(호스트 이름,호스트(도메인)의 IP주소 조회){Google의 IP 주소를 출력합니다. (예: www.google.com/142.250.180.68)}
        System.out.println(Address); //(호스트 이름,호스트(도메인)의 IP주소 출력)
        InetAddress[] SW=InetAddress.getAllByName("www.naver.com"); //지정된 호스트(도메인)의 모든 IP주소를 배열로 반환.
        for(int i=0;i<SW.length;i++){
            System.out.println(SW[i]);
        }
        //Naver의 모든 IP 주소 목록을 배열로 출력합니다. (예: www.naver.com/223.130.195.200, www.naver.com/223.130.200.107 등)
    }
}