//인스턴스 변수 선언
package OOP.ClassBasic;

public class Box{
    public double width;
    public double height;
    public double depth;

    //void 메서드는 반환값이 없는 메서드
    public void volume(){
        System.out.print("Volume is ");
        System.out.println(width*height*depth);
    }
}