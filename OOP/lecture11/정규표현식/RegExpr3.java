package OOP.lecture11.정규표현식;
import java.util.regex.*;
public class RegExpr3 {
    public static void main(String[] args){
        Pattern pat=Pattern.compile("test");
        Matcher mat=pat.matcher("test 1 2 3 test");

        while(mat.find()){
            System.out.println("test found at index "+mat.start()); //현재 매치된 문자 시퀀스의 시작 인덱스를 반환
        }
        //0, 11
    }
}