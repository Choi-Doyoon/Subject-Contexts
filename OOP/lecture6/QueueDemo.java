import java.util.LinkedList;
import java.util.NoSuchElementException; //예외처리문
import java.util.Queue;

public class QueueDemo {
    public static void main(String[] args){
        Queue<String> q=new LinkedList<>(); //큐 초기화 문법

        System.out.println(q.poll());//큐에서 삭제
        q.offer("Apple"); //큐에서 삽입
        System.out.println("Did you add Banana? "+q.offer("Banana"));

        try{
            q.add("Cherry");
        } catch(IllegalStateException e){}

        System.out.println("Head: "+q.peek()); //선입된 원소 검색
        String head=null;

        try{
            head=q.remove(); //Apple 제거
            System.out.println(head+" removed"); 
            System.out.println("New head: "+q.element()); //다음 선입 원소 검색
        } catch(NoSuchElementException e){}

        head=q.poll(); //선입된 원소 삭제
        System.out.println(head+" removed");
        System.out.println("New head: "+q.peek());
    }
}
