import java.util.HashMap;
import java.util.Map;

public class HashMap1Demo {
    public static void main(String[] args){
        Map<String,Integer> map=Map.of("Apple",5,"Banana",3,"Grape",10,"Strawberry",1);
        Map<String,Integer> fruits=new HashMap<>(map);

        System.out.println("# of fruit types: "+fruits.size()); //<String,Integer>이 한 세트

        fruits.remove("Banana"); //Banana와 3이 세트로 삭제
        System.out.println("# of fruit types: "+fruits.size());

        fruits.put("Mango",2); //새로운 키 한 쌍 삽입
        System.out.println("After adding Mango: "+fruits);

        fruits.clear(); //fruit 배열 전체 삭제
        System.out.println("# of fruit types: "+fruits.size());
    }
}
