package OOP.lecture5.override;

public class A {
    int i,j;
    public A(int i,int j){
        this.i=i;
        this.j=j;
    }

    void showij(){
        System.out.println("i: "+i+" j: "+j);
    }

    void show(){
        System.out.println("i: "+i+" j: "+j);
    }
}
