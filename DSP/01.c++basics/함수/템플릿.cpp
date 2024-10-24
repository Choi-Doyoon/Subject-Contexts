#include<iostream>
using namespace std;

template<typename T> //템플릿 사용(데이터 타입에 상관없이 여러 타입을 지원하는 함수를 작성 할 수 있음)
T max(T a, T b){
    return (a>b)?a:b;
}

int main(){
    cout<<"Max of 3 and 7: "<<max(3,7)<<endl;
    return 0;
}