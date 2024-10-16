package OOP.lecture9;
//Thread 클래스 상속 버전
public class ExtendThread {
    public static void main(String[] args){
        NThread nt=new NThread();

        nt.start(); //스레드 실행문

        try{
            for(int i=5;i>0;i--){
                System.out.println("Main Thread: "+i);
                Thread.sleep(1000);
            }
        } catch(InterruptedException e){
            System.out.println("Main thread interrupted.");
        }
        System.out.println("Main thread exiting.");
    }
}
