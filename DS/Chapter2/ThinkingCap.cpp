#include<iostream>
#include<cstdlib>
#include "Thinker.h"
using namespace std;
using namespace Main_Savitch_2A;

int main(){
    ThinkingCap student; //ThinkingCap 객체 생성
    ThinkingCap fan; //ThinkingCap 객체 생성

    student.slots("Hello","Goodbye"); //student 객체에 대해 slots 함수 호출
    student.push_green();
    student.push_red(); 

    fan.slots("Go Cougars!", "Boo!"); //fan 객체에 대해 slots 함수 호출
    fan.push_green();
    fan.push_red();
}