package OOP.lecture8.예외처리;

public class ThrowsDemo {
    static void throwOne(){
        throw new IllegalAccessException("demo");
    }

    public static void main(String[] args){
        throwOne();
    }
}
