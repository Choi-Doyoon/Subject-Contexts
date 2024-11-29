package OOP.lecture15;

interface MyFunc<T>{
    MyClass<T> func(T v);
}

class MyClass<T>{
    private T val;

    MyClass(T v){
        val = v;
    }

    MyClass(){
        val = null;
    }

    T getVal(){
        return val;
    }
}

public class ConstructorRefDemo2 {
    public static void main(String[] args){
        MyFunc<Integer> myClassCons = MyClass<Integer>::new;
        MyClass<Integer> mc = myClassCons.func(100);
        System.out.println("val in mc is " + mc.getVal());
    }
}
