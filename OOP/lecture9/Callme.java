package OOP.lecture9;

public class Callme {
    synchronized void call(String msg){ //동기화로 레이스 컨디션 없애기
        System.out.print("["+msg);
        try{
            Thread.sleep(1000);
        } catch(InterruptedException e){
            System.out.println("Interrupted");
        }
        System.out.println("]");
    }
}
