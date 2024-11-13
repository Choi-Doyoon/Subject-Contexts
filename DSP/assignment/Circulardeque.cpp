#include<iostream>
using namespace std;

template<typename T>
class Deque{
private:
    struct Node{
        T data;
        Node* next;
        Node* prev;

        Node(T value) : data(value), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* tail;
    int dequesize;

public:
    Deque() : head(nullptr), tail(nullptr), dequesize(0) {
        head=tail=nullptr;
    }

    ~Deque(){
        while(!isempty()){
            pop_front();
        }
    }

    void push_front(T data){
        Node* newNode = new Node(data);
        if(isempty()){
            head = tail = newNode;
            head->next = head->prev = head;
        }
        else{
            newNode->next = head;
            newNode->prev = tail;
            head->prev = newNode;
            tail->next = newNode;
            head = newNode;
        }
        dequesize++;
    }

    void push_back(T data){
        Node* newNode = new Node(data);
        if(isempty()){
            head = tail = newNode;
            head->next = head->prev = head;
        }
        else{
            newNode->next = head;
            newNode->prev = tail;
            head->prev = newNode;
            tail->next = newNode;
            tail = newNode;
        }
        dequesize++;
    }

    T pop_front(){
        if(isempty()){
            throw runtime_error("Deque is empty");
        }
        T data = head->data;
        if(head == tail){
            delete head;
            head = tail = nullptr;
        }
        else{
            Node* temp = head;
            head = head->next;
            head->prev = tail;
            tail->next = head;
            delete temp;
        }
        dequesize--;
        return data;
    }

    T pop_back(){
        if(isempty()){
            throw runtime_error("Deque is empty");
        }
        T data = tail->data;
        if(head == tail){
            delete tail;
            head = tail = nullptr;
        }
        else{
            Node* temp = tail;
            tail = tail->prev;
            tail->next = head;
            head->prev = tail;
            delete temp;
        }
        dequesize--;
        return data;
    }

    void display() const{
        if(isempty()){
            cout<<"Deque is empty"<<endl;
            return;
        }
        Node* current = head;
        do{
            cout<<current->data<<" ";
            current = current->next;
        } while(current != head);
        cout<<endl;
    }

    int size() const{
        return dequesize;
    }

    bool isempty() const{
        return head == tail && dequesize == 0;
    }
};

int main(){
    Deque<int> deque;

    cout<<"--- push_back 3 times ---"<<endl;
    deque.push_back(10);
    deque.push_back(7);
    deque.push_back(5);
    cout<<"size : "<<deque.size()<<endl;
    deque.display();

    cout<<"--- push_front 2 times ---"<<endl;
    deque.push_front(8);
    deque.push_front(6);
    cout<<"size : "<<deque.size()<<endl;
    deque.display();

    cout<<"--- pop_back 1 times ---"<<endl;
    cout<<deque.pop_back()<<endl;
    cout<<"size : "<<deque.size()<<endl;
    deque.display();

    cout<<"--- pop_front 3 times ---"<<endl;
    cout<<deque.pop_front()<<endl;
    cout<<deque.pop_front()<<endl;
    cout<<deque.pop_front()<<endl;
    cout<<"size : "<<deque.size()<<endl;
    deque.display();

    return 0;
}