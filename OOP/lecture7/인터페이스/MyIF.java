package OOP.lecture7.인터페이스;

public interface MyIF {
    int getNumber();

    default String getString(){
        return "default String";
    }
    //default 메서드는 클래스에서 구현할 필요 없는 메서드가 있을 때 사용한다.

    static int getDefaultNumber(){
        return 0;
    }
    //static 메서드는 해당 인터페이스명.static 메서드 이름() 으로 호출을 한다.
}
/*
 * MyIFImp 클래스에서 getNumber 메서드를 다 만든 후
 * MyIFImp obj = new MyIFImp();
 * obj.gerNumber();
 * obj.getString(); <----구현 없이 호출 가능하다.
 */
