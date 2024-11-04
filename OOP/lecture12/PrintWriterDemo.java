import java.io.*;

public class PrintWriterDemo {
    public static void main(String[] args) {
        PrintWriter pw = new PrintWriter(System.out, true);
        //flushingOn = true(println() 호출 시 버퍼에 있는 데이터 처리할지 결정)
        pw.println("This is a string");
        int i = -7;
        pw.println(i);
        double d= 4.5e-7;
        pw.println(d);
    }
}
