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
public:
    Queue(int maxSize):data(new T[maxSize]),capacity(maxSize),frontIndex(0), rearIndex(-1),count(0) {}
    ~Queue(){
        delete[] data;
    }

    bool empty() const{
        return count == 0;
    }

    bool full() const{
        return count == capacity;
    }

    int size() const{
        return count;
    }

    T& front(){
        if(!empty()){
            return data[frontIndex];
        }
    }

    const T& front() const{
        if(!empty()){
            return data[frontIndex];
        }
    }

    T& back(){
        if(!empty()){
            return data[rearIndex];
        }
    }

    const T& back() const{
        if (!empty()){
            return data[rearIndex];
        }
    }

    void push(const T& item){
        rearIndex++;
        data[rearIndex]=item;
        count++;
    }

    void pop(){
        if(!empty()){
            frontIndex++;
            count--;
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

    cout<<"큐의 크기: "<<queue.size()<<endl;
    cout<<"큐의 가장 앞 요소: "<<queue.front()<<endl;
    cout<<"큐의 가장 뒤 요소: "<<queue.back()<<endl;

    queue.push(40);

    queue.pop();
    cout<<"pop() 실행 후 가장 앞 요소: "<<queue.front()<<endl;

    while(!queue.empty()){
        cout<<"요소 제거: "<<queue.front()<<endl;
        queue.pop();
    }

    return 0;
}