#include<iostream>
using namespace std;

int main(){
    int num;
    do{
        cin>>num;
        if(num!=0){
            cout<<"You entered: " <<num<<endl;
        }
    } while(num!=0);
}

/*do{
    반복할 코드
    } while(조건);
*/