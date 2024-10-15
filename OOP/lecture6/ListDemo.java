import java.util.Arrays;
import java.util.List;

public class ListDemo{
    public static void main(String[] args){
        String[] animals1={"Deer","Tiger","Seal","Bear"}; //배열 정의

        List<String> animals2=Arrays.asList(animals1); //배열->리스트
        animals2.set(1,"Parrot");
        
        for(String s:animals2){
            System.out.println(s+",");
        }
        System.out.println();

        String[] animals3=animals2.toArray(new String[0]); //리스트->배열
        for(int i=0;i<animals3.length;i++){
            System.out.print(animals3[i]+",");
        }
        System.out.println();

        List<String> car=List.of("그랜져","소나타","아반떼","제네시스"); //불변리스트 선언(변화X)
        car.forEach(s->System.out.print(s+" "));
    }
}