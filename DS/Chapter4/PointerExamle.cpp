#include<iostream>
using namespace std;

int main(){
    int i=42;
    int j=80;
    int *p1,*p2;
    p1=&i;
    p2=&j;
    p2=p1;
    cout<<*p1<<endl; //42
    cout<<*p2<<endl; //42
    cout<<i<<endl; //42
    cout<<j<<endl; //80

    *p2=*p1; //j=42
    cout<<*p1<<endl; //42
    cout<<*p2<<endl; //42
    cout<<i<<endl; //42
    cout<<j<<endl; //42
}