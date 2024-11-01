package OOP.lecture11.정규표현식;
import java.util.regex.*;
public class RegExpr8 {
    public static void main(String[] args){
        String str="Jon Jonathan Frank Ken Todd";

        Pattern pat=Pattern.compile("Jon.*? ");
        Matcher mat=pat.matcher(str);

        str=mat.replaceAll("Eric "); //regex로 시작하는 모든 문자열을 Eric으로 변경

        System.out.println(str); // Eric Eric Frank Ken Todd
    }
}
