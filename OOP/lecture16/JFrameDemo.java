package OOP.lecture16;
import javax.swing.JFrame;
class MyFrame extends JFrame{
    MyFrame(){
        setTitle("안녕, 스윙!");
        setSize(300, 100);
        setVisible(true);
    }
}

public class JFrameDemo {
    public static void main(String[] args){
        new MyFrame();
    }    
}
