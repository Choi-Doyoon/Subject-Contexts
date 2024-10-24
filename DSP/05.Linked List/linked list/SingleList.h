#pragma once
#include<iostream>
using namespace std;

struct Node {
	int data;
	struct Node* link;
};

struct HeadNode {
	Node* head;
};

class singleList {
public:
	HeadNode* createList() {
		HeadNode* H = new HeadNode;
		H->head = NULL;
		return H;
	}

	void addNode(HeadNode* H, int x) {
		Node* NewNode = new Node;
		Node* LastNode;
		NewNode->data = x;
		NewNode->link = NULL;

		if (H->head == NULL) {
			H->head = NewNode;
			return;
		}

		LastNode = H->head;
		while (LastNode->link != NULL)LastNode = LastNode->link;
		LastNode->link = NewNode;
	}

	void addThisNode(HeadNode* H, int afterthisdata, int adddata) {
		Node* prevNode;
		prevNode = H->head;
		while (prevNode->data != afterthisdata) {
			prevNode = prevNode->link;
		}

		Node* NewNode = new Node;
		NewNode->data = adddata;
		NewNode->link = prevNode->link;
		prevNode->link = NewNode;
		return;
	}

	void searchNode(HeadNode* H, int thisdata) {
		Node* someNode;
		someNode = H->head;

		while (someNode->data != thisdata) {
			someNode = someNode->link;
		}
		cout << thisdata << "데이터 검색 성공" << endl;
	}

	void printList(HeadNode* L) {
		Node* p;
		cout << "연결리스트 목록 = ( ";
		p = L->head;
		while (p != NULL) {
			cout << p->data;
			p = p->link;
			if (p != NULL)cout << " --> ";
		}
		cout << " )" << endl;
	}

	void deleteNode(HeadNode* H) {
		Node* prevNode;
		Node* delNode;

		if (H->head == NULL) return;
		if (H->head->link == NULL) {
			delete H->head;
			H->head = NULL;
			return;
		}
		else {
			prevNode = H->head;
			delNode = H->head->link;
			while (delNode->link != NULL) {
				prevNode = delNode;
				delNode = prevNode->link;
			}
			free(delNode);
			prevNode->link = NULL;
		}
	}

	void deleteThisNode(HeadNode* H, int deldata) {
		Node* delNode;
		Node* prevNode;
		prevNode = H->head;
		while (prevNode->link->data != deldata) {
			prevNode = prevNode->link;
		}
		delNode = prevNode->link;
		prevNode->link = delNode->link;
		free(delNode);

		cout << deldata << " 데이터 값을 가진 노드 삭제" << endl;
		return;
	}
};