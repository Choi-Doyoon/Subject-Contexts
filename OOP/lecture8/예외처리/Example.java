package OOP.lecture8.예외처리;

public class Example {
    public static void main(String[] args){
        for(int i=0;i<10;i++){
            try{
                int a=12345/i;
                System.out.println("a: "+a);   
            } catch(ArithmeticException e){
                System.out.println("Division by zero.");
                
            }
             
        }
    }
}
