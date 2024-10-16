#include<iostream>
#include<queue>
using namespace std;

template<class Item>
class queue{
    public:
    typedef size_t size_type;
    queue(){
        count=0;
        front_ptr=NULL;
    }
    queue(const queue<Item>& source){ //copy constructor
        count=source.count;
        list_copy(source.front_ptr,front_ptr,rear_ptr);
    }
    ~queue(){list_clear(front_ptr);}
    void pop(){
        assert(!empty());
        list_head_remove(front_ptr);
        --count;
    }
    void push(const Item& entry){
        if(empty()){
            list_head_insert(front_ptr,entry);
            rear_ptr=front_ptr;
        }
        else{
            list_insert(rear_ptr,entry);
            rear_ptr=rear_ptr->link();
        }
        ++count;
    }
    void operator =(const queue<Item>& source){
        if(this==&source){return;}
        list_clear(front_ptr);
        list_copy(source.front_ptr,front_ptr,rear_ptr);
        count=source.count;
    }
    bool empty() const{return (count==0);}
    Item front() const{
        assert(!empty());
        return front_ptr->data();
    }
    size_type size() const {return count;}
    private:
    node<Item> *front_ptr;
    node<Item> *rear_ptr;
    size_type count;
};