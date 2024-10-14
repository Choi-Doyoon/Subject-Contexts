#ifndef THINKER_H
#include<iostream>
using namespace std;

namespace Main_Savitch_2A{
    class ThinkingCap{
    private:
        string green_string;
        string red_string;
    public:
        ThinkingCap(); //Constructor(생성자)
        void slots(string new_green, string new_red){
            green_string=new_green;
            red_string=new_red;
        }
        void push_green() const{cout<<green_string<<endl;} //함수+const : 함수 호출 후에 원래 값을 유지 시키는 것(const 역할), 수정 안하는 함수 역할
        void push_red() const{cout<<red_string<<endl;}
    };
}
#endif 