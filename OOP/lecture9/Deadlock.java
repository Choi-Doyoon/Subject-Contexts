package OOP.lecture9;
//데드락 현상(스레드가 영원히 대기상태가 됨)
public class Deadlock implements Runnable{
    A a=new A();
    B b=new B();
    Thread t;

    Deadlock(){
        Thread.currentThread().setName("MainThread");
        t=new Thread(this,"RacingThread");
    }

    public void run(){
        b.bar(a); //get lock on b in other thread.
        System.out.println("Back in other thread");
    }

    void deadlockStart(){
        t.start();
        a.foo(b); //get lock on a in this thread.
        System.out.println("Back in main thread");
    }

    public static void main(String[] args){
        Deadlock d1=new Deadlock();

        d1.deadlockStart();
    }
}
