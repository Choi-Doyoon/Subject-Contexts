package OOP.lecture7;

public class B implements A.NestedIf {
    public boolean isNotNegative(int x){
        return x<0? false: true;
    }
}
/*...
 * A.NestedIf nif=new B();
 */