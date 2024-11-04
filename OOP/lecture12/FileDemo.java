import java.io.File;

public class FileDemo {
    static void p(String s){
        System.out.println(s);
    }

    public static void main(String[] args){
        File f1 = new File("/java/COPYRIGHT"); //File 생성자


        p("File Name: " + f1.getName()); //파일 이름 반환
        p("Path: " + f1.getPath()); //파일 경로 반환
        p("Abs Path: " + f1.getAbsolutePath()); //파일의 절대 경로 반환
        p("Parent: " + f1.getParent()); //상위 경로 반환
        p(f1.exists() ? "exists" : "does not exist"); //파일의 존재 유무 반환
        p(f1.canWrite() ? "is writeable" : "is not writeable"); //작성 가능 파일인지 여부 반환
        p(f1.canRead() ? "is readable" : "is not readable"); //읽을 수 있는 파일인지 여부 반환
        p("is " + (f1.isDirectory() ? "" : "not" + " a directory")); //폴더 존재 유무 반환
        p(f1.isFile() ? "is normal file" : "might be a named pipe"); //파일 존재 유무 반환
        p(f1.isAbsolute() ? "is absolute" : "is not absolute"); //절대적인지 유무 반환
        p("File last modified: " + f1.lastModified()); //파일의 마지막 수정 시간을 반환
        p("File size: " + f1.length() + " Bytes"); //파일의 크기 반환
    }
}
