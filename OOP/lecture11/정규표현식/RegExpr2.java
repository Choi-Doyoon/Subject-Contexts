package OOP.lecture11.정규표현식;
import java.util.regex.*;
public class RegExpr2 {
    public static void main(String[] args){
        Pattern pat=Pattern.compile("Java");
        Matcher mat=pat.matcher("Java SE");

        if(mat.find()){ //문자열 일부 표현식과 매치되는지 여부 리턴
            System.out.println("subsequence found");
        }
        else{
            System.out.println("No Match");
        }
    }
}