package OOP.lecture17;
import java.awt.event.*;
import javax.swing.*;
public class HelloEventDemo extends JFrame{
    HelloEventDemo(){
        setTitle("이벤트 맛보기");

        ActionListener l = e->System.out.println("버튼을 클릭했습니다.");

        JButton b = new JButton("클릭");
        b.addActionListener(l);

        add(b);

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(200,100);
        setVisible(true);
    }

    public static void main(String[] args){
        new HelloEventDemo();
    }
}
