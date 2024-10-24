#include<iostream>
using namespace std;

int main(){
    //선언 및 초기화
    int numbers[5]; //상수형 배열, 5개의 요소를 저장할 수 있음
    int numbers[5]={1,2,3,4,5};

    //데이터 접근
    int numbers[5]={1,2,3,4,5};
    cout<<numbers[0]<<endl; //1출력
    numbers[2]-10; // 배열의 3번째 요소를 10으로 변경
}