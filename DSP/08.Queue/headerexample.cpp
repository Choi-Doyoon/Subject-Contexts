#include<iostream>
#include<queue>
using namespace std;

int main(){
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout<<"큐의 크기: "<<q.size()<<endl;
    cout<<"큐의 가장 앞 요소: "<<q.front()<<endl;
    cout<<"큐의 가장 뒤 요소: "<<q.back()<<endl;

    q.pop();
    cout<<"pop() 실행 후 가장 앞 요소: "<<q.front()<<endl;

    while(!q.empty()){
        cout<<"요소 크기: "<<q.front()<<endl;
        q.pop();
    }

    return 0;
}