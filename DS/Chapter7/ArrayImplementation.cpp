#include<iostream>
#include<stack>
#include<cctype>
#include<cstring>
using namespace std;

//배열 구현
template<class Item>
class stack{
    private:
    Item data[CAPACITY];
    size_type used;
    public:
    stack(){used=0;} //생성자

    void push(const Item& entry){
        assert(size()<CAPACITY);
        data[used]=entry;
        ++used;
    }

    void pop(){
        assert(!empty());
        --used;
    }

    Item top() const{
        assert(!empty());
        return data[used-1];
    }

    bool empty() const{return used==0;}

    size_type size() const{return used;}
};