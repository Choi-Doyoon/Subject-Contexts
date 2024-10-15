package OOP.lecture8.인터페이스;

public class Rectangle implements Figure {//Rectangle 클래스가 Figure 인터페이스 참조
    public void area(double width,double height){ //추상 메서드 몸통 부분 첨가
        System.out.println(width*height);
    }

    //구현 시 추가로 메서드 정의 가능
}
