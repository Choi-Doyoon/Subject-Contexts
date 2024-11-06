package OOP.lecture14;


class NonGen{  //Object는 모든 타입을 가리킬 수 있음
    Object ob;

    NonGen(Object o){
        ob=o;
    }

    Object getOb(){
        return ob;
    }

    void showType(){
        System.out.println("Type of ob is "+ob.getClass().getName());
    }
}

public class NonGenDemo {
    public static void main(String[] args){
        NonGen iOb;

        iOb = new NonGen(88);
        iOb.showType();

        int v=(Integer) iOb.getOb();  //Integer로 다운캐스팅(오토박싱)
        System.out.println("value: "+v);

        NonGen strOb=new NonGen("Non-Generics Test");
        strOb.showType();

        String str=(String) strOb.getOb();
        System.out.println("value: "+str);

        //runtime exception!
        //iOb = strOb; (NonGen이라 호환은 가능)
        //v=(Integer) iOb.getOb(); (문자열을 정수로 캐스팅 할려고 하니까 호환이 안되서 런타임 에러 발생)
    }    
}
