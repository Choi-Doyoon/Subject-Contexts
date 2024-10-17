package OOP.lecture8.예외처리;

public class Zero {
    public static void main(String[] args){
        try{
            int d=0;
            int a=42/d;
            System.out.println(a);
            System.out.println("Not printed.");
        } catch(ArithmeticException e){
            System.out.println("Division by zero.");
        }
        System.out.println("This will be printed.");
    }
}
