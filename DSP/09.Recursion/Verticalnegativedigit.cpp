#include<iostream>
#include<cmath> //abs 함수를 사용하기 위함
using namespace std;

void write_vertical(int number){
    if(number<0){
        cout<<"-"<<endl;
        write_vertical(abs(number));
    }
    else if(number<10){
        cout<<number<<endl;
    }
    else{
        write_vertical(number/10);
        cout<<number % 10<<endl;
    }
}

int main(){
    int number;
    cout<<"Enter a number: ";
    cin>>number;
    write_vertical(number);
    return 0;
}