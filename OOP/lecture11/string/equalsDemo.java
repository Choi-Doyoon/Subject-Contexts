package OOP.lecture11.string;
//문자열 비교
public class equalsDemo {
    public static void main(String[] args){
        String s1="Hello";
        String s2="Hello";
        String s3="Good-bye";
        String s4="HELLO";

        System.out.println(s1 + " equals " + s2 + " -> " + s1.equals(s2)); //equals() 메소드는 두 문자열이 같은지 비교
        System.out.println(s1 + " equals " + s3 + " -> " + s1.equals(s3));
        System.out.println(s1 + " equals " + s4 + " -> " + s1.equals(s4));
        System.out.println(s1 + " equalsIgnoreCase " + s4 + " -> " + s1.equalsIgnoreCase(s4)); //대소문자 구분 없이 비교
    }
}
