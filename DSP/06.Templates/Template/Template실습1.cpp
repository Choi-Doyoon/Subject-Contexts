#include<iostream>
#include<string>
using namespace std;

template<typename T>
T sum(T a,T b){return a+b;}

int main(){
    int ia=1, ib=2;
    double da=2.5,db=2.8;
    string sa="Hello",sb="World!";

    cout<<"int 합: "<<sum<int>(ia,ib)<<endl;
    cout<<"double 합: "<<sum<double>(da,db)<<endl;
    cout<<"string 합: "<<sum<string>(sa,sb)<<endl;

    return 0;
}