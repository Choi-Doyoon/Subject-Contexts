#include<iostream>
#include<cctype>
#include<stack>
#include<cstring>
using namespace std;

template<class Item>
class stack{
    private:
    node<Item> *top_ptr;
    public:
    stack(const stack<Item>& source){
        node<Item>* tail_ptr;
        list_copy(source.top_ptr,top_ptr,tail_ptr);
    }

    void push(const Item& entry){
        list_head_insert(top_ptr entry);
    }

    void pop(){
        assert(!empty());
        list_head_remove(top_ptr);
    }

    bool empty() const{
        return top_ptr==NULL;
    }

    Item top() const{
        assert(!empty());
        return top_ptr->data();
    }
};