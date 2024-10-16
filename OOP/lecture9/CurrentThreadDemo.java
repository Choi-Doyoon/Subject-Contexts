package OOP.lecture9;

public class CurrentThreadDemo {
    public static void main(String[] args){
        Thread t=Thread.currentThread(); //현재 실행 스레드의 오브젝트 참조를 반환

        System.out.println("Current thread: "+t); //t는 스레드로 초기화한 상태
    }
}
