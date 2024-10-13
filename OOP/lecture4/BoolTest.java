//논리 타입 예제(boolean)
public class BoolTest {
    public static void main(String[] args){
        boolean b;
        b = false;
        System.out.println("b is " + b);
        b = true;
        System.out.println("b is " + b);
        //boolean 타입은 true, false 두 가지 값만 가질 수 있다. 
        if(b) System.out.println("This is executed."); //조건문에서 그냥 boolean 선언시 true로 초기화한다.(값 비교(==) 불필요)
        b = false;
        if(b) System.out.println("This is not executed.");
        //if문은 조건식이 true일 때만 실행된다.
        System.out.println("10 > 9 is " + (10 > 9)); //조건식 결과는 boolean으로 출력
    }
}
