#include<iostream>
using namespace std;

int main(){
    char grade;
    cin>>grade;

    switch(grade){
        case 'A':
            cout<<"Excellent"<<endl;
            break;
        case 'B':
            cout<<"Good job!"<<endl;
            break;
        default: //default문은 반드시 존재할 필요 X
            cout<<"Keep trying"<<endl;
    }
}

/*
  switch(조건 변수 혹은 조건식){
    case 상수식1:
        실행문1;
        break;
    case 상수식2:
        실행문2;
        break;
    default:
        실행문3;
        break;
  }
*/