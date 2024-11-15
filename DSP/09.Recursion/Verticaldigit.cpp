#include<iostream>
using namespace std;

void write_vertical(unsigned int number){
    if(number<10){
        cout<<number<<endl; //base case: 한 자리 숫자일 경우 바로 출력
    }
    else{
        write_vertical(number/10); //recursive call: 숫자를 10으로 나눈 몫을 재귀적으로 출력
        cout<<number%10<<endl; //현재 자리의 숫자를 출력
    }
}

int main(){
    unsigned int number;
    cout<<"Enter a number: ";
    cin>>number;
    write_vertical(number);
    return 0;
}