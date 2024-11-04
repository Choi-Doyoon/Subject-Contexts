import java.io.*;

public class CopyFile2 {
    public static void main(String[] args) throws IOException{
        int i;

        if(args.length!=2){
            System.out.println("Usage: CopyFile from to ");
            return;
        }

        try(FileInputStream fin=new FileInputStream(args[0]); FileOutputStream fout = new FileOutputStream(args[1])){
            //2개 이상의 자원을 명시 할 때는 세미콜론으로 구분
            do{
                i=fin.read();
                if(i!=-1){fout.write(i);}
            }while(i!=-1);
        } catch(IOException e){
            System.out.println("I/O Error: "+e);
        }
    }
}
