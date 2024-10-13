package OOP;

public class IfSample {
    public static void main(String[] args){
        int x,y;
        x=10;
        y=20;
        if(x<y) System.out.println("x is less than y");

        x=x*2;
        if(x==y) System.out.println("x is now equal to y");

        x=x*2;
        if(x>y) System.out.println("x is now greater than y");

        // 이건 출력X(이유: x>y)
        if(x==y) System.out.println("You won't see this");
    }
}
