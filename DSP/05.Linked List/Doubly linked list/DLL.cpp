#include<iostream>
#include "DoubleList.h"
using namespace std;

void main() {
	doubleList list;
	HeadNode* L;
	L = list.createList();

	cout << "1. 빈 연결 리스트 생성" << endl << endl;

	int data1, data2, data3;
	cout << "2. 연결 리스트에 추가할 노드 데이터 3개 입력: ";
	cin >> data1 >> data2 >> data3;
	list.addEndNode(L, data1);
	list.printList(L);
	list.addEndNode(L, data2);
	list.printList(L);
	list.addEndNode(L, data3);
	list.printList(L);
	cout << endl;

	cout << "3-1. 데이터를 뒤에 추가할 노드 입력 (끝 노드는 입력하지 말 것): ";
	cin >> data1;
	cout << "3-2. 추가하고 싶은 값 입력: ";
	cin >> data2;
	list.addThisNode(L, data1, data2);
	list.printList(L);
	cout << endl;

	cout << "4-1. 삭제하고자 하는 노드 1 입력: ";
	cin >> data1;
	list.deleteNode(L, data1);
	list.printList(L);
	cout << endl;

	cout << "4-2. 삭제하고자 하는 노드 2 입력: ";
	cin >> data2;
	list.deleteNode(L, data2);
	list.printList(L);
	cout << endl;

	cout << "4-3. 삭제하고자 하는 노드 3 입력: ";
	cin >> data3;
	list.deleteNode(L, data3);
	list.printList(L);
	cout << endl;

	cout << "4-4. 삭제하고자 하는 노드 4 입력: ";
	cin >> data1;
	list.deleteNode(L, data1);
	list.printList(L);
	cout << endl;
}