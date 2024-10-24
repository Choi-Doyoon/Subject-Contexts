#include<iostream>
using namespace std;

class ThinkingCap{
    public:
    void slots(string new_green, string new_red){
        green_string=new_green;
        red_string=new_red;
    }
    void push_green() const{cout<<green_string<<endl;}
    void push_red() const{cout<<red_string<<endl;}
    private:
    string green_string;
    string red_string;
};