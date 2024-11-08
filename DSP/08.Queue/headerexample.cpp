#include<iostream>
#include<queue>
using namespace std;

int main(){
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout<<"ť�� ũ��: "<<q.size()<<endl;
    cout<<"ť�� ���� �� ���: "<<q.front()<<endl;
    cout<<"ť�� ���� �� ���: "<<q.back()<<endl;

    q.pop();
    cout<<"pop() ���� �� ���� �� ���: "<<q.front()<<endl;

    while(!q.empty()){
        cout<<"��� ũ��: "<<q.front()<<endl;
        q.pop();
    }

    return 0;
}