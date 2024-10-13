package OOP.lecture2.javabasic;

public class ForTest {
    public static void main(String[] args){
        int x;
        for(x=0; x<10; x=x+1) //제어문 변수 x 초기화
        //매 루프마다 조건식 평가해서 True이면 실행문 실행
            System.out.println("This is x: "+x);
    }
    //(x=x+1) == (x++)
}
