#include<iostream>
#include<string>
using namespace std;

template<typename T>
class Vector{
    T* data;
    int capacity;
    int length;

    public:
    Vector(int n=1):data(new T[n]),capacity(n),length(0){}
    void push_back(T s){
        if(capcity<=length){
            T* temp=new T[capacity*2];
            for(int i=0;i<length;i++){
                temp[i]=data[i];
            }
            delete[] data;
            data=temp;
            capacity*=2;
        }
        data[length]=5;
        length++;
    }
    
    T operator[](int i){return data[i];}

    void remove(int x){
        for(int i=x+1;i<length;i++){
            data[i-1]=data[i];
        }
        length--;
    }

    int size(){return length;}

    ~Vector(){
        if(data){
            delete[] data;
        }
    }
};

int main(){
    Vector<int> int_vec;
    int_vec.push_back(3);
    int_vec.push_back(2);

    cout<<"--------int vector--------"<<endl;
    cout<<"첫 번째 원소: "<<int_vec[0]<<endl;
    cout<<"두 번째 원소: "<<int_vec[1]<<endl;

    Vector<string> str_vec;
    str_vec.push_back("Hello");
    str_vec.push_back("world!");

    cout<<"--------string vector--------"<<endl;
    cout<<"첫 번째 원소: "<<str_vec[0]<<endl;
    cout<<"두 번째 원소: "<<str_vec[1]<<endl;

    return 0;
}