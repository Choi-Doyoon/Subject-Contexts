package OOP.lecture5.override;

public class B extends A{
    int k;
    public B(int i, int j, int k){
        super(i,j);
        this.k=k;
    }
    void showk(){
        System.out.println(k);
    }

    void sum(){
        System.out.println(i+j+k);
    }

    //show() 메서드 오버라이드
    void show(){
        super.show();
        System.out.println("k: "+k);
    }
}
