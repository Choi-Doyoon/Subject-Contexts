#include<iostream>
using namespace std;
//This code has an error
template<typename T>
class Queue{
private:
    T* data;
    int capacity;
    int frontIndex;
    int rearIndex;
    int count;

    void resize(int newCapacity){
        T* newData=new T[newCapacity];
        for(int i=0;i<count;++i){
            newData[i]=data[(frontIndex+i)%capacity];
        }
        delete[] data;
        data=newData;
        capacity=newCapacity;
        frontIndex=0;
        rearIndex=count-1;
    }

public:
    Queue(int maxSize):data(new T[maxSize]),capacity(maxSize),frontIndex(0), rearIndex(-1),count(0) {}
    ~Queue(){
        delete[] data;
    }

    bool empty() const{
        return count == 0;
    }

    int size() const{
        return count;
    }

    T& front(){
        if(!empty()){
            return data[frontIndex];
        }
        else{
            throw runtime_error("ť�� ��� �ֽ��ϴ�.");
        }
    }

    const T& front() const{
        if(!empty()){
            return data[frontIndex];
        }
        else{
            throw runtime_error("�� ��� �ֽ��ϴ�.");
        }
    }

    T& back(){
        if(!empty()){
            return data[rearIndex];
        }
        else{
            throw runtime_error("�� ��� �ֽ��ϴ�.");
        }
    }

    const T& back() const{
        if (!empty()){
            return data[rearIndex];
        }
        else{
            throw runtime_error("�� ��� �ֽ��ϴ�.");
        }
    }

    void push(const T& item){
        if(count == capacity){
            resize(2*capacity);
        }
        rearIndex++;
        data[rearIndex]=item;
        count++;
    }

    void pop(){
        if(!empty()){
            frontIndex=(frontIndex + 1)%capacity;
            --count;
            if(count>0 && count == capacity/4){
                resize(capacity/2);
            }
        }
        else{
            throw runtime_error("�� ��� �ֽ��ϴ�.");
        }
    }

    void swap(Queue& other){
        swap(data,other.data);
        swap(capacity,other.capacity);
        swap(frontIndex,other.frontIndex);
        swap(rearIndex, other.rearIndex);
        swap(count,other.count);
    }
};

int main(){
    Queue<int> queue(3);

    queue.push(10);
    queue.push(20);
    queue.push(30);

    cout<<"ť�� ũ��: "<<queue.size()<<endl;
    cout<<"ť�� ���� �� ���: "<<queue.front()<<endl;
    cout<<"ť�� ���� �� ���: "<<queue.back()<<endl;

    queue.pop();
    cout<<"pop() ���� �� ���� �� ���: "<<queue.front()<<endl;

    while(!queue.empty()){
        cout<<"��� ����: "<<queue.front()<<endl;
        queue.pop();
    }

    return 0;
}