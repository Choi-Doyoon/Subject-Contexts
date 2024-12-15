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
            throw runtime_error("ť�� ��� �ֽ��ϴ�.");
        }
    }

    T& back(){
        if(!empty()){
            return rearNode->data;
        }
        else{
            throw runtime_error("���� ��� �ֽ��ϴ�.");
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
            throw runtime_error("���� ��� �ֽ��ϴ�. pop�� ������ �� �����ϴ�.");
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