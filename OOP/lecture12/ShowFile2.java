import java.io.*;

public class ShowFile2 {
    public static void main(String[] args){
        int i;
        if(args.length!=1){
            System.out.println("Usage: ShowFile2 filename");
            return;
        }

        //오류 발생
        try(FileInputStream fin = new FileInputStream(args[0])){//출력 스트림 X
            do{
                i=fin.read();
                if(i!=-1) {System.out.print((char) i);}
            }while(i!=-1);
        }catch(FileNotFoundException e){
            System.out.println("An I/O Error Occurred");
        }
    }
}
