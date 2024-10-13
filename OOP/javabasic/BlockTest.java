package OOP.javabasic;

public class BlockTest {
    public static void main(String[] args){
        int x,y;
        y=20;

        for(x=0; x<10; x=x+1){
            System.out.println("This is x: "+x);
            System.out.println("This is y: "+y);
            y=y-2;
        }
    }
}
