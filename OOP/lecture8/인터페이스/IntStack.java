package OOP.lecture8.인터페이스;

public interface IntStack {
    default int[] popNElements(int n){
        return getElements(n);
    }

    default int[] skipAndPopNElements(int skip, int n){
        getElements(skip);
        return getElements(n);
    }

    private int[] getElements(int n){
        int[] elements=new int[n];
        for(int i=0;i<n;i++) elements[i]=pop();
        return elements;
    }
    //private 메서드는 default 메서드가 내부적으로 호출할 때 유용하며, 중복된 구현을 줄일 수 있다.
}
