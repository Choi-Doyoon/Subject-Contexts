package OOP.lecture14;

class Stats<T extends Number>{
    T[] nums;
    Stats(T[] o){
        nums=o;
    }
    double average(){
        double sum=0.0;
        for(int i=0;i<nums.length;i++){
            sum+=nums[i].doubleValue();
        }
        return sum/nums.length;
    }
    boolean isSameAvg(Stats<?> ob){
        if(average()==ob.average()){return true;}
        else{return false;}
    }
}
public class WildcardDemo {
    public static void main(String[] args){
        Integer[] inums = {1,2,3,4,5};
        Stats<Integer> iob=new Stats<Integer>(inums);
        double v=iob.average();
        System.out.println("iob average is "+v);

        Double[] dnums ={1.1,2.2,3.3,4.4,5.5};
        Stats<Double> dob=new Stats<Double>(dnums);
        double w= dob.average();
        System.out.println("dob average is: "+w);

        System.out.println("Averages of iob and dob");
        if(iob.isSameAvg(dob)){
            System.out.println("are the same.");
        }
        else{
            System.out.println("differ.");
        }
    }
}
