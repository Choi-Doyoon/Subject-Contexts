package OOP.lecture11.정규표현식;
import java.util.regex.*;
public class RegExpr7 {
    public static void main(String[] args){
        Pattern pat=Pattern.compile("[a-z]+");
        Matcher mat=pat.matcher("this is a test.");

        while(mat.find()){
            System.out.println("Match: "+mat.group()); 
        }
        /* this
         * is
         * a
         * test
         */
    }
}
