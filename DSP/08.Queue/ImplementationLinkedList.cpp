#include<iostream>
using namespace std;
//This code has an error
template<typename T>
class Queue{
private:
    struct Node{
        T data;
        Node* next;

        Node(const T& data, Node* next = nullptr) : data(data),next(next){}
    };
    
    Node* frontNode;
    Node* rearNode;
    int count;

public:
    Queue():frontNode(nullptr),rearNode(nullptr),count(0) {}
    ~Queue(){
        while(!empty()){
            pop();
        }
    }

    bool empty() const{
        return frontNode==nullptr;
    }

    int size() const{
        return count;
    }

    T& front(){
        if(!empty()){
            return frontNode->data;
        }
        else{
            throw runtime_error("큐가 비어 있습니다.");
        }
    }

    T& back(){
        if(!empty()){
            return rearNode->data;
        }
        else{
            throw runtime_error("쿠가 비어 있습니다.");
        }
    }

    void push(const T& item){
        Node* newNode=new Node(item);
        if(empty()){
            frontNode=rearNode=newNode;
        }
        else{
            rearNode->next=newNode;
            rearNode=newNode;
        }
        count++;
    }

    void pop(){
        if(!empty()){
            Node* temp=frontNode;
            frontNode=frontNode->next;
            delete temp;
            --count;
            if(frontNode == nullptr){
                rearNode=nullptr;
            }
        }
        else{
            throw runtime_error("쿠가 비어 있습니다. pop을 수행할 수 없습니다.");
        }
    }

    void swap(Queue& other){
        swap(frontNode,other,frontNode);
        swap(rearNode,other.rearNode);
        swap(count,other.count);
    }
};

int main(){
    Queue<int> queue;

    queue.push(10);
    queue.push(20);
    queue.push(30);

    cout<<"큐의 크기: "<<queue.size()<<endl;
    cout<<"큐의 가장 앞 요소: "<<queue.front()<<endl;
    cout<<"큐의 가장 뒤 요소: "<<queue.back()<<endl;

    queue.pop();
    cout<<"pop() 실행 후 가장 앞 요소: "<<queue.front()<<endl;

    while(!queue.empty()){
        cout<<"요소 제거: "<<queue.front()<<endl;
        queue.pop();
    }

    return 0;
}