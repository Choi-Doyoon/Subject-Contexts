package OOP.lecture2.ClassBasic;

public class BoxDemo6 {
    public static void main(String[] args){
        Box2 mybox1= new Box2();
        Box2 mybox2= new Box2();
        double vol;

        // get volume of first box
        vol = mybox1.volume();
        System.out.println("Volume is " + vol);

        // get volume of second box
        vol = mybox2.volume();
        System.out.println("Volume is " + vol);
  }
}
