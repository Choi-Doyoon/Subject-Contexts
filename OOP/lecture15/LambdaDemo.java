package  OOP.lecture15;

interface MyNumber{
    double getValue();
}

public class LambdaDemo{
    public static void main(String[] args){
        MyNumber myNum;
        myNum = () -> 123.45;
        System.out.println("A fixed value: " + myNum.getValue());
        myNum = () -> Math.random() * 100; //람다식을 사용하여 무작위 값 생성
        System.out.println("A random value: " + myNum.getValue());
        System.out.println("Another random value: " + myNum.getValue());
        //myNum = () -> "123.45"; //에러 발생(타입 불일치)
    }
}