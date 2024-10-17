package OOP.lecture5.qwer;
abstract class A {
    abstract void callme(); //추상 메서드

    //추상 클래스 내부에 일반 메서드도 정의 가능
    void callmetoo(){
        System.out.println("concrete method");
    }

    final void meth(){
        System.out.println("final method");
    }



    //final로 지정된 클래스는 상속 불가능
}
