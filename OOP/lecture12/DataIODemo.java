import java.io.*;

public class DataIODemo {
    public static void main(String[] args) throws IOException{
        //First, write the data.
        try(DataOutputStream dout = new DataOutputStream(new FileOutputStream("Test.dat"))){ //출력 데이터 생성자
            dout.writeDouble(98.6);
            dout.writeInt(1000);
            dout.writeBoolean(true);
        } catch(FileNotFoundException e){
            System.out.println("Cannot Open Output File");
            return;
        } catch(IOException e){
            System.out.println("I/O Error: "+e);
        }

        //Now, read the data back.
        try(DataInputStream din= new DataInputStream(new FileInputStream("Test.dat"))){ //입력 데이터 생성자
            double d=din.readDouble();
            int i=din.readInt();
            boolean b= din.readBoolean();

            System.out.println("Here are the value: "+d+" "+i+" "+b);
        } catch(FileNotFoundException e){
            System.out.println("Cannot Open Input File");
            return;
        } catch(IOException e){
            System.out.println("I/O Error: "+e);
        }
    }
}
