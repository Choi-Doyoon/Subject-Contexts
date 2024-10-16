package OOP.lecture9;
//Thread 클래스를 상속하는 방법
public class NThread extends Thread{
    NThread(){//생성자
        super(); //Thread 클래스 상속 키워드
        System.out.println("Child thread: "+this);
    }

    public void run(){
        try{
            for(int i=5;i>0;i--){
                System.out.println("Child Thread: "+i);
                Thread.sleep(500);
            }
        } catch(InterruptedException e){
            System.out.println("Child interrupted.");
        }
        System.out.println("Exiting child thread.");
    }
}

