package OOP.lecture2.ClassBasic;

public class Box3 {
    public double width;
    public double height;
    public double depth;

    //생성자 생성(인스턴스 변수 초기화)
    //this 키워드는 메서드에서 오브젝트를 참조할 때 사용(매개변수와 인스턴스 변수 동일 이름일 때 사용 가능)
    public Box3(double width, double height, double depth){
        this.width=width;
        this.height=height;
        this.depth=depth;
    }

    public double volume(){
        return width*height*depth;
    }
}
