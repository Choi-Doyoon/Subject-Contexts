import java.util.Stack;

public class StackDemo {
    public static void main(String[] args){
        Stack<String> s1=new Stack<>(); //스택 초기화 문법

        s1.push("Apple");
        s1.push("Banana");
        s1.push("Cherry");

        System.out.println(s1.peek()); //스택의 top을 제거하지 않고 엿본다

        System.out.println(s1.pop()); //스택을 하나 씩 반환하면서 제거한다.
        System.out.println(s1.pop());
        System.out.println(s1.pop());
        System.out.println();

        Stack<Integer> s2=new Stack<>();

        s2.add(10);
        s2.add(20);
        s2.add(1,100); //1번 인덱스에 100 추가

        for(int value:s2){
            System.out.println(value+" ");
        }
        System.out.println();

        while(!s2.empty()){
            System.out.print(s2.pop()+" ");
        }
    }
}
