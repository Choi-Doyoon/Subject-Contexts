import java.io.*;

public class CopyFile {
    public static void main(String[] args) throws IOException{
        int i;
        FileInputStream fin=null;
        FileOutputStream fout=null;

        //파일 이름 유효성 검사
        if(args.length !=2){
            System.out.println("Usage: Copyfile from to");
            return;
            //복사할 파일 이름이 제대로 입려되지 않으면 프로그램 종료
        }

        try{
            fin=new FileInputStream(args[0]); //원본 파일 열기
            fout=new FileOutputStream(args[1]); //복사 대상 파일(두 번쨰 인자) 열기
            do{ 
                i=fin.read(); //원본 파일에서 한 바이트씩 읽어서 i에 저장
                if(i!=-1){fout.write(i);} //i의 값을 복사 대상 파일에 기록
            } while(i!=-1);
        }catch(IOException e){
            System.out.println("I/O Error: "+e);
        }finally{ //파일 스트림 닫기
            try{
                if(fin!=null){fin.close();}
            }catch(IOException e2){
                System.out.println("Error Closing Input File");
            }
            try{
                if(fout!=null){fout.close();}
            }catch(IOException e2){
                System.out.println("Error Closing Output File");
            }
        }
    }
}
