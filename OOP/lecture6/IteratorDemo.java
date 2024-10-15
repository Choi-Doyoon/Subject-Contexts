import java.util.*;
public class IteratorDemo {
    public static void main(String[] args){
        Collection<String> list=Arrays.asList("A","B","C");

        Iterator<String> iterator=list.iterator();
        while(iterator.hasNext()){
            System.out.println(iterator.next()+",");
        }
        System.out.println();
    }
}
