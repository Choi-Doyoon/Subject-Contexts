package OOP.lecture9;
//Runnable 인터페이스 구현
public class NewThread implements Runnable { //Runnable은 java 키워드이다.
    Thread t; //스레드 타입 선언

    NewThread(){ //생성자
        t= new Thread(this);
        System.out.println("Chile thread: "+t);
    }

    public void run(){ //Runnable 상속 때문에 run메서드 정의가 필요하다.
        try{
            for(int i=5;i>0;i--){
                System.out.println("Child Thread: "+i);
                Thread.sleep(500);
            }
        } catch (InterruptedException e){
            System.out.println("Child interrupted.");
        }
        System.out.println("Exiting child thread.");
    }
}
