#include<iostream>
#include<cstdlib>
#include "Thinker.h"
using namespace std;

int main(){
    ThinkingCap student;
    ThinkingCap fan;

    student.slots("Hello","Goodbye");
    student.push_green();
    fan.slots("Go Cougars!","BOO!");
    fan.push_green();
    student.push_red();
}