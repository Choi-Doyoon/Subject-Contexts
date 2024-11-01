#include<iostream>
using namespace std;

template<typename T>
class Stack{
private:
    T* data;
    int capacity;
    int topIndex;

    void resize(int newCapacity){
        T* newData = new T[newCapacity];
        for(int i=0; i<topIndex; i++){
            newData[i] = data[i];
        }
        delete[] data;
        data=newData;
        capacity = newCapacity;
    }
public:
    //기본 생성자
    Stack() : data(new T[1]), capacity(1), topIndex(0) {}

    //복사 생성자
    Stack(const Stack& other): data(new T[other.capacity]), capacity(other.capacity), topIndex(other.topIndex){
        for(int i=0; i<topIndex; i++){
            data[i] = other.data[i];
        }
    }

    //소멸자
    ~Stack(){
        delete[] data;
    }

    //대입 연산자 오버로딩
    Stack& operator=(Stack other){
        swap(other);
        return *this;
    }

    void push(const T& item){
        if(topIndex==capacity){
            resize(2*capacity); //스택이 가득 찼다면 크기를 2배로 늘림
        }
        data[topIndex++] = item;
    }

    void pop(){
        if(!isEmpty()){
            --topIndex;
            if(topIndex > 0 && topIndex == capacity/4){
                resize(capacity/2); //스택이 1/4로 찼다면 크기를 1/2로 줄임
            }
        }
        else{
            cout<<"스택이 비어있습니다. pop을 수행할 수 없습니다."<<endl;
        }
    }

    T top() const{
        if(!isEmpty()){
            return data[topIndex-1];
        }
        else{
            cout<<"스택이 비어있습니다."<<endl;
            return T();
        }
    }

    bool isEmpty() const{
        return topIndex==0;
    }

    int size() const{
        return topIndex;
    }

    void swap(Stack& other){
        swap(data, other.data);
        swap(capacity, other.capacity);
        swap(topIndex, other.topIndex);
    }
};

int main(){
    Stack<int> stack1;
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);

    Stack<int> stack2;
    stack2.push(10);
    stack2.push(20);

    cout<<"교환 전: "<<endl;
    cout<<"stack1의 촤상단 요소: "<<stack1.top()<<endl;
    cout<<"stack2의 촤상단 요소: "<<stack2.top()<<endl;

    stack1.swap(stack2);

    cout<<"\n swap 교환 후: "<<endl;
    cout<<"stack1의 촤상단 요소: "<<stack1.top()<<endl;
    cout<<"stack2의 촤상단 요소: "<<stack2.top()<<endl;

    stack1=stack2;

    cout<<"\n 대입 연산자 오버로딩 후: "<<endl;
    cout<<"stack1의 촤상단 요소: "<<stack1.top()<<endl;
    cout<<"stack2의 촤상단 요소: "<<stack2.top()<<endl;

    return 0;
}