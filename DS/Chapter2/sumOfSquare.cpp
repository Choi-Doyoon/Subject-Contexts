#include<iostream>
using namespace std;

int sumOfSquare(const int& a, const int& b){
    return a*a+b*b;
}

int main(){
    int x=1;
    int y=0;
    int i=sumOfSquare(x,y);
    cout<<x<<endl;
    cout<<y<<endl;
    cout<<i<<endl;
}