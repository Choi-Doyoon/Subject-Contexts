#include<iostream>
using namespace std;

int date_check(int year, int month=1,int day=1){
    cout<<year<<", "<<month<<", "<<day<<endl;
}


int main(){
    date_check(200); //same as date_check(2000,1,1)
    date_check(2000,7); //same as date_check(2000,2,1)
}
