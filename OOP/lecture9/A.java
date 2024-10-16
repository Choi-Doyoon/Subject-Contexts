package OOP.lecture9;
//데드락 현상(스레드가 영원히 대기 상태가 됨)
public class A {
    synchronized void foo(B b){
        String name=Thread.currentThread().getName();
        System.out.println(name+" entered A.foo");
        System.out.println(name+" call B.last()");
        b.last();
    }

    synchronized void last(){
        System.out.println("Inside A.last");
    }
}
