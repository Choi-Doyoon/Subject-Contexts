package OOP.lecture15;

interface MyFunc{
    int func(int n);
}

public class VarCapture {
    public static void main(String[] args){
        int num = 10;
        MyFunc myLambda = (n) -> {
            int v = num + n;
            //num++; //에러 발생(람다식 내에서 외부 변수 변경 불가)
            return v;
        };
        //num = 9; //에러 발생(람다식 내에서 외부 변수 변경 불가)
        System.out.println(myLambda.func(8));
    }    
}
