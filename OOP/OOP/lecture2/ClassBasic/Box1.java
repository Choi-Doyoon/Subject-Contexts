package OOP.lecture2.ClassBasic;

public class Box1 {
    public double width;
    public double height;
    public double depth;

    public double volume(){
        return width*height*depth;
    }

    //매서드를 이용한 변수 초기화
    public void setDim(double w, double h, double d){
        width=w;
        height=h;
        depth=d;
    }
}
