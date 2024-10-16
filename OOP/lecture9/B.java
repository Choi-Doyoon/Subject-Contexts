package OOP.lecture9;
//데드락 현상(스레드가 영원히 대기 상태가 됨)
public class B {
    synchronized void bar(A a){
        String name=Thread.currentThread().getName();
        System.out.println(name+" entered B.bar");
        System.out.println(name+" call A.last()");
        a.last();
    }

    synchronized void last(){
        System.out.println("Inside B.last");
    }
}
