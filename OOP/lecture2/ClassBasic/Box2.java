package OOP.lecture2.ClassBasic;

public class Box2 {
    public double width;
    public double height;
    public double depth;

    //생성자 생성(인스턴스 변수 초기화)
    public Box2(){
        System.out.println("Constructing Box");
        width=10;
        height=10;
        depth=10;
    }

    public double volume(){
        return width*height*depth;
    }
}
