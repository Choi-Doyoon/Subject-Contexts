package OOP.lecture2.ClassBasic;

public class BoxDemo2 {
    public static void main(String[] args){
        Box mybox1= new Box(); //Box타입의 오브젝트 생성(오브젝트 참조)
        Box mybox2= new Box(); //Box타입의 오브젝트 생성(오브젝트 참조)
        double vol;

        mybox1.width=10; //오브젝트 참조 변수명.인스턴스 변수명(.연사자를 이용해 인스턴스 변수 접근)
        mybox1.height=20;
        mybox1.depth=15;

        //mybox1와는 다른 변수를 가지는 오브젝트 생성
        mybox2.width=3; //오브젝트 참조 변수명.인스턴스 변수명(.연사자를 이용해 인스턴스 변수 접근)
        mybox2.height=6;
        mybox2.depth=9;

        vol=mybox1.width*mybox1.height*mybox1.depth;
        System.out.println("Volume is "+vol);

        vol=mybox2.width*mybox2.height*mybox2.depth;
        System.out.println("Volume is "+vol);
    }
}
