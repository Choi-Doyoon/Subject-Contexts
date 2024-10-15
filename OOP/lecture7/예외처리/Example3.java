package OOP.lecture7.예외처리;

public class Example3 {
    public static void main(String[] args){
        try{
            int a=0;
            int b=42/a;
        } catch (ArithmeticException e){
            System.out.println("Caught");
        } finally{
            System.out.println("Finally");
        }
    }
}
