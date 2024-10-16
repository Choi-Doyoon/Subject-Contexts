package OOP.lecture10;
public class Test {
    public static void main(String[] args){
        enum Apple{Jonathan,GoldenDel,RedDel, Winesap}

        Apple ap=Apple.RedDel;
        Apple ap2=Apple.GoldenDel;
        System.out.println(ap.compareTo(ap2));
        System.out.println(ap.equals(ap2));
    }
}
