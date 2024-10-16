package OOP.lecture9;

public class ThreadDemo {
    public static void main(String[] args){
        try{
            NewThread nt=new NewThread();
            nt.t.start(); //t=new Thread(this) ,, 스레드 실행문

            for(int i=5;i>0;i--){
                System.out.println("Main Thread: "+i);
                Thread.sleep(1000);
            }
        } catch(InterruptedException e){
            System.out.println("Main thread interrupted.");
        }
        System.out.println("Main thread exiting");
    }
}
