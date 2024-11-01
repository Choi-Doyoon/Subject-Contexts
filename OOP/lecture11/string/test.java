package OOP.lecture11.string;

public class test{
    public static void main(String[] args){
        char[] chars={'a','b','c'};
        String s = new String(chars);
        System.out.println(s.length()); //오브젝트에 포함된 문자 개수 반환

        String age="9";
        String t="He is "+age+"years old."; //+연산자를 이용해 문자열을 이을 수 있음
        System.out.println(t);
        //긴 문자열을 선언할 때 유용
        String longstr  = "This could have been "+
                        "a very long line that would have "+
                        "wrapped around. But string concatenation "+
                        "prevents this.";
        System.out.println(longstr);
    }
}