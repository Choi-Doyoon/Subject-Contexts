import java.io.File;

public class DirList {
    public static void main(String[] args){
        String dirname="/java";
        File f1=new File(dirname); //File 생성자

        if(f1.isDirectory()){ //true->file 오브젝트가 directory를 연다.
            System.out.println("Directory of "+dirname);
            String[] s = f1.list(); //하위 디렉토리와 파일을 반환

            for(int i=0;i<s.length;i++){
                File f=new File(dirname+"/"+s[i]);
                if(f.isDirectory()){
                    System.out.println(s[i]+" is a directory");
                }
                else{
                    System.out.println(s[i]+" is a file");
                }
            }
        }
        else{
            System.out.println(dirname+" is not a directory");
        }
    }
}
