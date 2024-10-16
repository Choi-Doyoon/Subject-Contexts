package OOP.lecture9;

public class Producer implements Runnable{
    Q q;
    Thread t;

    Producer(Q q){ //생성자
        this.q=q;
        t=new Thread(this,"Producer");
    }

    public void run(){
        int i=0;
        while(true){
            q.put(i++);
        }
    }
    
}
