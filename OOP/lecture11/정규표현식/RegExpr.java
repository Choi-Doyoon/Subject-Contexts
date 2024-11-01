package OOP.lecture11.정규표현식;
import java.util.regex.*;
public class RegExpr {
    public static void main(String[] args){
        Pattern pat;
        Matcher mat;
        boolean found;

        pat=Pattern.compile("Java"); //regex을 받아 오브젝트 Pattern 생성
        mat=pat.matcher("Java");

        found=mat.matches(); //Matcher 생성 시 받았던 인자가 매치되는지 여부 리턴(문자열 전체가 정규표현식과 매치되어야함)
        if(found){
            System.out.println("Matches");
        }
        else{
            System.out.println("Not Match");
        }

        mat=pat.matcher("Java SE");
        found=mat.matches();
        if(found){
            System.out.println("Matches");
        }
        else{
            System.out.println("Not Match");
        }
    }
}