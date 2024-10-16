package OOP.lecture9;

public class Q {
    int n;
    boolean valueSet=false;

    synchronized int get(){
        try{
            if(!valueSet){ //오버플로우 방지
                wait();
            }
        } catch(InterruptedException e){
            System.out.println("InterruptedException");
        }
        System.out.println("Got: "+n);
        valueSet=false;
        notify();
        return n;
    }

    synchronized void put(int n){
        try{
            if(valueSet){
                wait();
            } 
        } catch(InterruptedException e){
            System.out.println("InterruptedException");
        }
        this.n=n;
        valueSet=true;
        System.out.println("Put: "+n);
        notify();
    }
}
