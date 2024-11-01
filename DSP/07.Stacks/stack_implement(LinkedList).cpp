#include<iostream>
using namespace std;

template<typename T>
class Stack{
private:
    //노드 구조체 정의
    struct Node{
        T data;
        Node* next;
        Node(const T& data, Node* next=nullptr) : data(data), next(next) {}
    };

    Node* topNode;
    int count;
    
public:
    //기본 생성자
    Stack(): topNode(nullptr), count(0){}

    //복수 생성자
    Stack(const Stack& other): topNode(nullptr), count(0){
        if(other.topNode == nullptr){
            return;
        }

        topNode = new Node(other.topNode->data);
        Node* current = topNode;
        Node* otherCurrent = other.topNode->next;

        while(otherCurrent != nullptr){
            current->next = new Node(otherCurrent->data);
            current = current->next;
            otherCurrent = otherCurrent->next;
        }
        count = other.count;
    }

    //소멸자
    ~Stack(){
        while(!isEmpty()){
            pop();
        }
    }

    //대입 연산자 오버로딩
    Stack& operator=(Stack other){
        if(this != &other){
            Stack temp(other);
            swap(temp);
        }
        return *this;
    }

    void push(const T& item){
        topNode=new Node(item,topNode);
        ++count;
    }

    void pop(){
        if(!isEmpty()){
            Node* temp=topNode;
            topNode=topNode->next;
            delete temp;
            --count;
        }
        else{
            cout<<"stack is empty. can't use pop()."<<endl;
        }
    }

    T top() const{
        if(!isEmpty()){
            return topNode->data;
        }
        else{
            cout<<"stack is empty."<<endl;
            return T();
        }
    }

    bool isEmpty() const{
        return topNode == nullptr;
    }

    int size() const{
        return count;
    }

    void swap(Stack& other){
        swap(topNode, other.topNode);
        swap(count, other.count);
    }
};

int main(){
    Stack<int> stack1;
    stack1.push(10);
    stack1.push(20);
    stack1.push(30);

    cout<<"stack1 size: "<<stack1.size()<<endl;
    cout<<"stack1's top element: "<<stack1.top()<<endl;

    stack1.pop();
    cout<<"stack1's top element after pop(): "<<stack1.top()<<endl;

    while(!stack1.isEmpty()){
        cout<<"delete element: "<<stack1.top()<<endl;
        stack1.pop();
    }

    return 0;
}