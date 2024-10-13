package OOP.lecture2.ClassBasic;

public class BoxDemo3 {
    public static void main(String[] args){
        Box mybox1= new Box(); //Box타입의 오브젝트 생성(오브젝트 참조)
        Box mybox2= new Box(); //Box타입의 오브젝트 생성(오브젝트 참조)

        mybox1.width=10; //오브젝트 참조 변수명.인스턴스 변수명(.연산자를 이용해 인스턴스 변수 접근)
        mybox1.height=20;
        mybox1.depth=15;

        mybox2.width=3; //오브젝트 참조 변수명.인스턴스 변수명(.연산자를 이용해 인스턴스 변수 접근)
        mybox2.height=6;
        mybox2.depth=9;

        mybox1.volume();
        mybox2.volume();
    }
}
