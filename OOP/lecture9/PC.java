package OOP.lecture9;

public class PC {
    public static void main(String[] args){
        Q q=new Q();
        Producer p=new Producer(q);
        Consumer c=new Consumer(q);

        //스레드 실행
        p.t.start();
        c.t.start();

        System.out.println("Press Control-C to stop.");
    }
}
