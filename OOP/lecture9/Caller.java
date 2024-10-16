package OOP.lecture9;

public class Caller implements Runnable{
    String msg;
    Callme target;
    Thread t;

    public Caller(Callme targ, String s){
        target=targ;
        msg=s;
        t=new Thread(this);
    }

    public void run(){
        synchronized(target){ //동기화로 레이스 컨디션 없애기
            target.call(msg);
        }
    }
}
