package OOP.lecture11.정규표현식;
import java.util.regex.*;
public class RegExpr9 {
    public static void main(String[] args){
        Pattern pat=Pattern.compile("[ ,.!]");
        
        String[] strs=pat.split("one two,alpha0 12!done."); //문자열을 정규표현식대로 분리

        for(int i=0;i<strs.length;i++){
            System.out.println("Next token: "+strs[i]); 
        }
        /* one
         * two
         * alpha9
         * 12
         * done
         */
    }
}
