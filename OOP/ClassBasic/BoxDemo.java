package OOP.ClassBasic;
/* -오브젝트 생성-
 * new 키워드 사용
 */
public class BoxDemo {
    public static void main(String[] args){
        Box mybox= new Box(); //Box타입의 오브젝트 생성(오브젝트 참조)
        double vol;

        mybox.width=10; //오브젝트 참조 변수명.인스턴스 변수명(.연사자를 이용해 인스턴스 변수 접근)
        mybox.height=20;
        mybox.depth=15;

        vol=mybox.width*mybox.height*mybox.depth;
        System.out.println("Volume is "+vol);
    }
}
