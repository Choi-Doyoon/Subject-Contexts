package OOP.lecture11.정규표현식;
import java.util.regex.*;
public class RegExpr4 {
    public static void main(String[] args){
        Pattern pat=Pattern.compile("W+"); //W+는 W,WW,WWW,WWWW...이 되는것이다.(한정자)
        Matcher mat=pat.matcher("W WW WWW");

        while(mat.find()){
            System.out.println("Match: "+mat.group()); //마지막으로 매칭된 문자열 부분을 리턴
        }
        /* W
         * WW
         * WWW
         */
    }
}
