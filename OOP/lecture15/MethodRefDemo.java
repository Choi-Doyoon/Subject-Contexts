package OOP.lecture15;

interface StringFunc{
    String func(String n);
}

class MyStringOps{
    String strReverse(String str){
        String result = "";
        int i;
        for(i=str.length()-1; i>=0; i--){
            result += str.charAt(i);
        }
        return result;
    }
}

public class MethodRefDemo {
    static String stringOp(StringFunc sf, String s){
        return sf.func(s);
    }

    public static void main(String[] args){
        String inStr = "Lambdas add power to Java";
        String outStr;
        outStr = stringOp(new MyStringOps()::strReverse, inStr); //오브젝트 메서드 참조
        System.out.println("Original string: " + inStr);
        System.out.println("String reversed: " + outStr);
    }    
}
