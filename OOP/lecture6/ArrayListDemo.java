import java.util.ArrayList;
import java.util.List;

public class ArrayListDemo {
    public static void main(String[] args){
        List<String> list=List.of("그랜져","소나타","아반떼","제네시스","소울");

        System.out.println(list.indexOf("소나타"));
        System.out.println(list.contains("산타페"));

        List<String> cars1=new ArrayList<>(list); //cars1이라는 동적배열을 list 기반으로 생성
        cars1.add("Santa Fe");  //cars1에 Santa Fe 추가

        cars1.removeIf(c->c.startsWith("So")); //So로 시작하는 원소가 있으면 삭제
        cars1.replaceAll(s->"New "+s); //모든 원소 앞에 New라는 단어를 붙여서 교체
        cars1.forEach(s->System.out.print(s+" "));
        System.out.println();

        cars1.clear(); //배열 전체 삭제
        System.out.println(cars1.isEmpty()); //배열이 비었는지 확인
    }
}
