#include<iostream>
using namespace std;

template<typename T>
class Stack{
private:
    //노드 구조체 정의
    struct Node{
        T data;
        Node* next;
        Node(const T& data, Node* next=nullptr): data(data), next(next){}
    };

    Node* topNode;
    int count;
public:
    //기본 생성자
    Stack(): topNode(nullptr), count(0){}

    //소멸자
    ~Stack(){
        while(!isEmpty()){
            pop();
        }
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
            cout<<"스택이 비어있습니다. pop을 수행할 수 없습니다."<<endl;
        }
    }

    T top() const{
        if(!isEmpty()){
            return topNode->data;
        }
        else{
            cout<<"스택이 비어있습니다."<<endl;
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

    cout<<"스택의 크기: "<<stack1.size()<<endl;
    cout<<"스택의 최상단 원소: "<<stack1.top()<<endl;

    stack1.pop();
    cout<<"pop() 호출 후 스택의 최상단 원소: "<<stack1.top()<<endl;

    while(!stack1.isEmpty()){
        cout<<"요소 제거: "<<stack1.top()<<endl;
        stack1.pop();
    }

    return 0;
}