package OOP.lecture11.string;

public class Box {
    double width;
    double height;
    double depth;

    Box(double w, double h, double d){
        width = w;
        height = h;
        depth = d;
    }

    //문자열 반환(오브젝트를 String으로 반환)
    public String toString(){
        return "Dimensions are " + width + " by " + depth + " by " + height + ".";
    }
}
