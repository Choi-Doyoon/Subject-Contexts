public class Scope {
    public static void main(String[] args){
        int x;
        x = 10;
        if(x == 10){
            int y = 20;
            System.out.println("x and y: " + x + " " + y);
            x = y * 2;
        }
        //y = 100; //error: 변수를 선언한 블록을 벗어나면 변수를 사용할 수 없다.
        //x는 아직 선언됨.
        //System.out.println("x is " + x + " y is " + y); //error: cannot find symbol
    }
}
