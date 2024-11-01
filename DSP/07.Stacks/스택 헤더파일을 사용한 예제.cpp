#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<int> s1; //정수를 담는 스택 s1 선언

    //스택이 비어있는지 확인
    if(s1.empty()){
        cout<<"스택 s1은 비어있습니다."<<endl;
    }

    //스택에 원소 추가
    s1.push(10);
    s1.push(20);
    s1.push(30);
    cout<<"스택 s1의 크기: "<<s1.size()<<endl;

    //스택의 상단 원소 출력
    cout<<"스택 s1의 상단 원소: "<<s1.top()<<endl;

    //스택에서 상단 원소 제거
    s1.pop();
    cout<<"pop() 호출 후 스택 s1의 상단 원소: "<<s1.top()<<endl;

    //emplace를 사용하여 스택에 원소 추가
    s1.emplace(40);
    cout<<"emplace() 호출 후 스택 s1의 상단 원소: "<<s1.top()<<endl;

    //스택 s1의 모든 원소를 스택 s2와 교환
    stack<int> s2; //정수를 담는 스택 s2 선언
    s2.push(100);
    s2.push(200);

    cout<<"교환 전 스택 s1의 상단 원소: "<<s1.top()<<endl;
    cout<<"교환 전 스택 s2의 상단 원소: "<<s2.top()<<endl;

    s1.swap(s2); //교환

    cout<<"교환 후 스택 s1의 상단 원소: "<<s1.top()<<endl;
    cout<<"교환 후 스택 s2의 상단 원소: "<<s2.top()<<endl;

    return 0;
}