#include<iostream>
using namespace std;

void write_vertical(int number){
    if(number < 0){
        cout << "-";
        write_vertical(abs(number));
    }
    else if(number < 10){
        cout << number << endl;
    }
    else{
        write_vertical(number / 10); //recursive call
        cout << number % 10 << endl;
    }
}

int main(){
    write_vertical(1234);
    return 0;
}