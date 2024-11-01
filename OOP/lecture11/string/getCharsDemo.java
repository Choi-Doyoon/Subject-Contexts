package OOP.lecture11.string;

public class getCharsDemo {
    public static void main(String[] args){
        String s="This is a demo of the getChars method.";
        int start=10;
        int end=14;
        char[] buf=new char[end-start];

        s.getChars(start,end,buf,0); //문자열 s의 start부터 end까지의 문자를 buf[0]부터 복사
        System.out.println(buf);
    }
}
