package OOP.lecture2.ClassBasic;

public class BoxDemo7 {
    public static void main(String[] args) {
      // declare, allocate, and initialize Box objects
      Box3 mybox1 = new Box3(10, 20, 15);
      Box3 mybox2 = new Box3(3, 6, 9);
  
      double vol;
  
      // get volume of first box
      vol = mybox1.volume();
      System.out.println("Volume is " + vol);
  
      // get volume of second box
      vol = mybox2.volume();
      System.out.println("Volume is " + vol);
    }
  }