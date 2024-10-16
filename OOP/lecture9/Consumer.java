package OOP.lecture9;

public class Consumer implements Runnable{
    Q q;
    Thread t;

    Consumer(Q q){ //생성자
        this.q=q;
        t=new Thread(this,"Consumer");
    }

    public void run(){
        while(true){
            q.get();
        }
    }
}
