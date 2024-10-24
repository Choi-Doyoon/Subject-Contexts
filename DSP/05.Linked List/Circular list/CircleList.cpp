#include<iostream>
#include "CircleList.h"
using namespace std;

int main() {
	CircleList list;

	HeadNode* L;
	L = list.createList();

	cout << "1. 빈 원형 연결 리스트를 생성" << endl << endl;

	int data1, data2, data3;
	cout << "2-1. 원형 연결 리스트 맨 앞 노드 추가: ";
	cin >> data1;
	list.addFirstNode(L, data1);
	list.printList(L);

	cout << "2-2. 원형 연결 리스트 맨 앞 노드 추가: ";
	cin >> data2;
	list.addFirstNode(L, data2);
	list.printList(L);

	cout << "2-3. 원형 연결 리스트 맨 앞 노드 추가: ";
	cin >> data3;
	list.addFirstNode(L, data3);
	list.printList(L);
	cout << endl;

	cout << "3. 원형 연결 리스트 중간에 노드를 삽입 " << endl;
	cout << "3-1. 데이터를 삽입할 노드 선택: ";
	int data4, data5;
	cin >> data4;
	cout << "3-2. 삽입하고 싶은 값 입력: ";
	cin >> data5;
	list.addMiddleNode(L, data4, data5);
	list.printList(L);
	cout << endl;

	cout << "4-1. 삭제하고자 하는 노드 입력: ";
	int data6;
	cin >> data6;
	list.deleteCircleNode(L, data6);
	list.printList(L);
	cout << endl;

	cout << "4-2. 추가로 삭제하고 싶은 노드 입력: ";
	int data7;
	cin >> data7;
	list.deleteCircleNode(L, data7);
	list.printList(L);
	cout << endl;

	cout << "4-3. 추가로 삭제하고 싶은 노드 입력: ";
	int data8;
	cin >> data8;
	list.deleteCircleNode(L, data8);
	list.printList(L);
	cout << endl;
}