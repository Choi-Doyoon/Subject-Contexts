#include<iostream>
using namespace std;

int main(){
    int grade;
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