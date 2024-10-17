package OOP.lecture8.예외처리;

public class Example2 {
    public static void main(String[] args){
        try{
            int a=0;
            int b=42/a;
            int[] c={1};
            c[42]=99;
            System.out.println(b);
        } catch(ArithmeticException e){
            System.out.println("Divide by 0: "+e);
        } catch(ArrayIndexOutOfBoundsException e){
            System.out.println("Array oob: "+e);
        }
    }    
}
