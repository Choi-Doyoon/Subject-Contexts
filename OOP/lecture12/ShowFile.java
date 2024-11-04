import java.io.*;

public class ShowFile {
    public static void main(String[] args){
        int i;
        FileInputStream fin;

        //파일 유효성 검사
        if(args.length != 1){
            System.out.println("Usage: ShowFile filename");
            return;
        }

        //파일 열기
        try{
            fin = new FileInputStream(args[0]);
        } catch(FileNotFoundException e){
            System.out.println("Cannot Open File");
            return;
        }

        //파일 읽기
        try{
            do{
                i=fin.read();
                if(i!=-1){System.out.print((char) i);}
            } while(i!=-1);
        } catch(IOException e){
            System.out.println("Error Reading File");
        }

        //파일 닫기
        try{
            fin.close();
        } catch(IOException e){
            System.out.println("Error Closing File");
        }
    }
}
