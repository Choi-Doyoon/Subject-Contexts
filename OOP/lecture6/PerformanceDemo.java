import java.util.ArrayList;
import java.util.LinkedList;

public class PerformanceDemo {
    public static void main(String[] args){
        ArrayList<Integer> al=new ArrayList<Integer>();
        LinkedList<Integer> ll=new LinkedList<Integer>();

        long start=System.nanoTime(); //나노초단위로 반환
        for(int i=0;i<100000;++i){
            al.add(0,i);
        }
        long end=System.nanoTime();
        long duration=end-start;
        System.out.println("ArrayList processing time: "+duration);

        
        start=System.nanoTime();
        for(int i=0;i<100000;++i){
            ll.add(0,i);
        }
        end=System.nanoTime();
        duration=end-start;
        System.out.println("LinkedList processing tinme: "+duration);
    }
}
