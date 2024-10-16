package OOP.lecture9;

public class Synch {
    public static void main(String[] args){
        Callme target=new Callme();
        Caller ob1=new Caller(target,"Hello");
        Caller ob2=new Caller(target,"World");

        ob1.t.start();
        ob2.t.start();

        try{
            ob1.t.join();
            ob2.t.join();
        } catch(InterruptedException e){
            System.out.println("Interrupted);");
        }
    }
}
//call()에 대해 레이스 컨디션이 발생함.