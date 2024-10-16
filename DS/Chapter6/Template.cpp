#include<iostream>
using namespace std;

template<class Item>
Item maximum(Item a,Item b){
    if(a>b){return a;}
    else{return b;}
}

int main(){
    int x,y;
    cin>>x>>y;

    cout<<maximum(x,y)<<endl;
    cout<<maximum(1,2)<<endl;
    cout<<maximum(1.3,0.9)<<endl;
}