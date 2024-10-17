package OOP.lecture5.qwer;
public class C {
    public static void main(String[] args){
        //추상클래스는 인스턴스화 불가

        B b=new B();
        b.callme();
        b.meth();

        A a=b; //변수화해서 인스턴스화는 가능
        a.callmetoo();
        a.meth();
    }
}
