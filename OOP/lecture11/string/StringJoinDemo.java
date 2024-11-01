package OOP.lecture11.string;
//문자열 연결
public class StringJoinDemo {
    public static void main(String[] args){
        String result = String.join(" ","Alpha","Beta","Gamma");
        System.out.println(result);

        result = String.join(", ","John","ID#: 569","E-mail: John@herbSchildt.com");
        System.out.println(result);
    }
}
