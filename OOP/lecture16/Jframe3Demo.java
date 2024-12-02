package OOP.lecture16;
import javax.swing.*;
public class Jframe3Demo extends JFrame{
    Jframe3Demo(){
        setTitle("안녕, 스윙!");

        JButton b = new JButton("버튼");
        add(b);

        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setSize(300,100);
        setVisible(true);
    }

    public static void main(String[] args){
        new Jframe3Demo();
    }
}
