package OOP.lecture9;

public class DemoJoin {
    public static void main(String[] args){
        Otherthread nt1=new Otherthread("One");

        nt1.t.start();
        System.out.println("Thread One is alive: "+nt1.t.isAlive()); //isAlive = 스레드 실행 여부 확인
        try{
            nt1.t.join(); //스레드 종료까지 기다림
        } catch(InterruptedException e){
            System.out.println("Main thread Interrupted");
        }

        System.out.println("Thread One is Alive: "+nt1.t.isAlive());
        System.out.println("Main thread exiting.");
    }
}
