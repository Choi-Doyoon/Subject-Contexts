#include<iostream>
using namespace std;

int main(){
    int number;
    cin>>number;

    if(number>0){
        cout<<"number은 양수입니다."<<endl;
    }
    else if(number<0){
        cout<<"number는 음수입니다."<<endl;
    }
    else{
        cout<<"number는 0입니다."<<endl;
    }
}