#pragma once
#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* Llink;
	Node* Rlink;
};

struct HeadNode {
	Node* Lhead;
	Node* Rhead;
};

class doubleList {
public:
	HeadNode* createList() {
		HeadNode* H = new HeadNode;
		H->Lhead = NULL;
		H->Rhead = NULL;
		return H;
	}

	void addEndNode(HeadNode* H, int adddata) {
		Node* prevNode;
		Node* newNode = new Node;
		newNode->data = adddata;
		newNode->Llink = NULL;
		newNode->Rlink = NULL;

		if (H->Rhead == NULL) {
			H->Rhead = newNode;
			H->Lhead = newNode;
		}
		else {
			prevNode = H->Lhead;
			prevNode->Rlink = newNode;
			newNode->Llink = prevNode;
			H->Lhead = newNode;
		}
	}

	void addThisNode(HeadNode* H, int afterthisdata, int adddata) {
		Node* prevNode;
		Node* newNode = new Node;
		newNode->data = adddata;
		newNode->Llink = NULL;
		newNode->Rlink = NULL;

		prevNode = H->Rhead;
		while (prevNode->data != afterthisdata) {
			prevNode = prevNode->Rlink;
		}
		newNode->Rlink = prevNode->Rlink;
		newNode->Llink = prevNode;
		prevNode->Rlink = newNode;
		newNode->Rlink->Llink = newNode;
	}

	void deleteNode(HeadNode* H, int deldata) {
		Node* delNode;
		delNode = H->Rhead;
		if (delNode == NULL) return;
		while (delNode->data != deldata) {
			delNode = delNode->Rlink;
		}
		if (delNode == H->Lhead) {
			if (delNode == H->Rhead) {
				H->Rhead = NULL;
				H->Lhead = NULL;
			}
			else {
				delNode->Llink->Rlink = NULL;
				H->Lhead = delNode->Llink;
			}
		}
		else if (delNode == H->Rhead) {
			H->Rhead = delNode->Rlink;
			delNode->Rlink->Llink = NULL;
		}
		else {
			delNode->Llink->Rlink = delNode->Rlink;
			delNode->Rlink->Llink = delNode->Llink;
		}
		delete delNode;
		cout << deldata << "를 가지는 노드를 삭제" << endl;
	}

	void printList(HeadNode* L) {
		Node* p;
		p = L->Rhead;
		if (p== NULL) {
			cout << endl << "비어있는 연결 리스트" << endl << endl;
			return;
		}
		cout << "연결리스트 목록 = ( ";
		while (p != NULL) {
			cout << p->data;
			p = p->Rlink;
			if (p != NULL) cout << " --> ";
		}
		cout << " )" << endl << endl;
	}
};