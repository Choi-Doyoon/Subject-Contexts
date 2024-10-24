#include<iostream>
using namespace std;

int add(int a, int b){
    return a+b;
}

//add() 메서드 오버로딩(같은 이름의 함수를 여러번 정의, 매개변수의 타입이나 개수에 따라 구분됨)
double add(double a, double b){
    return a+b;
}

int main(){
    cout<<"Int addition: "<<add(5,3)<<endl;
    cout<<"Double addition: "<<add(5.5,3.3)<<endl;

    return 0;
}