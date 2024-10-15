package OOP.lecture7;

public class Area {
    public static void main(String[] args){
        //인터페이스로 구현 클래스 오브젝트 참조 가능
        Figure f=new Triangle();
        f.area(10,20);

        f=new Rectangle();
        f.area(10,20);
    }
}
