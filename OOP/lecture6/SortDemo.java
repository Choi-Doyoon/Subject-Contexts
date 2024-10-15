import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class SortDemo {
    public static void main(String[] args){
        String[] fruits={"Grape","Watermelon","Apple","Kiwi","Mango"};
        List<String> list=Arrays.asList(fruits);

        Collections.sort(list,Collections.reverseOrder()); //fruits 원소를 반대로 입력하고 내림차순으로 list에 입력
        System.out.println(list);

        Collections.reverse(list); //내림차순->오름차순
        System.out.println(list);
    }
}
