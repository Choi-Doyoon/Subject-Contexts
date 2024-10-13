package OOP.ClassBasic;

public class Stack {
    public int [] stck=new int[10];
    public int tos;

    public Stack(){
        tos=-1; //생성자에서 tos라는 변수를 -1로 초기화
    }

    public void push(int item){
        if(tos==9)
            System.out.println("Stack is full.");
        else
            stck[++tos]=item;
    }

    public int pop(){
        if(tos<0){
            System.out.println("Stack underflow.");
            return 0;
        }
        else
            return stck[tos--];
    }
}
