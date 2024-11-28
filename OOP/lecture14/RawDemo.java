package OOP.lecture14;

class Gen<T>{
    T ob;

    Gen(T o){
        ob=o;
    }

    T getOb(){
        return ob;
    }
}
public class RawDemo {
    public static void main(String[] args){
        Gen<Integer> iOb=new Gen<Integer>(88);
        Gen<String> strOb=new Gen<String>("Generics Test");

        Gen raw=new Gen(Double.valueOf(98.6));
        double d=(Double) raw.getOb();
        System.out.println("value: "+d);

        strOb=raw;
        //String str=strOb.getOb();
        //System.out.println("value: "+str);

        raw=iOb;
        //d=(Double) raw.getOb();
        //System.out.println("value: "+d);
    }
}
