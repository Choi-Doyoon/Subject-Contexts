#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prevNode;
    Node* nextNode;

    Node(int value) : data(value), prevNode(NULL), nextNode(NULL){}
};

class DoublyLinkedList {
private:
    Node* headNode;
    Node* tailNode;
public:
    DoublyLinkedList() {
        headNode = NULL;
        tailNode = NULL;
    }

    ~DoublyLinkedList() {
        delete headNode;
        delete tailNode;
    }
    
    void insertAtHead(int value) {
        Node* currentNode = new Node(value);
        if (headNode == NULL) {
            headNode = currentNode;
            tailNode = currentNode;
        }
        else {
            headNode->prevNode = currentNode;
            headNode = currentNode;
        }
    }

    void insertAtTail(int value) {
        Node* currentNode = new Node(value);
        if (tailNode == NULL) {
            headNode = currentNode;
            tailNode = currentNode;
        }
        else {
            tailNode->nextNode = currentNode;
            tailNode = currentNode;
        }
    }

    void deleteAtHead() {
        headNode = headNode->nextNode;
        headNode->prevNode = NULL;
    }

    void deleteAtTail() {
        tailNode = tailNode->prevNode;
        tailNode->nextNode = NULL;
    }

    void printList() {
        Node* currentNode = headNode;
        while (currentNode != NULL) {
            if (currentNode->nextNode == NULL) {
                cout << currentNode->data;
                break;
            }
            cout << currentNode->data;
            cout << "<->";
            currentNode = currentNode->nextNode;
        }
    }

    void clear() {
        headNode = NULL;
        tailNode = NULL;
    }

    Node* findNode(int value) {
        Node* currentNode = headNode;
        while (currentNode->data != value) {
            if (currentNode->data == value) {
                return currentNode;
            }
            currentNode = currentNode->nextNode;
        }
        return NULL;
    }

    bool empty() {
        if (headNode != NULL) {
            return true;
        }
        return false;
    }
};

int main() {
    DoublyLinkedList list;
    list.insertAtHead(3);
    list.insertAtTail(5);
    list.insertAtTail(2);
    //list.insertAt(1, 4);
    cout << "Initial List: ";
    list.printList();

    cout << "Reversed List: ";
    list.printReserveList();

   /* Node* foundNode = list.findNode(5);
    cout << (foundNode ? "Found 4" : "4 not found") << endl;*/

    /*list.deleteNode(8);

    list.deleteNode(5);
    cout << "After deleting 5: ";
    list.printList();*/

    /*list.deleteAtHead();
    cout << "After deleting head: ";
    list.printList();

    list.deleteAtTail();
    cout << "After deleting tail: ";
    list.printList();*/

    /*list.insertAt(5, 10);

    cout << (list.empty() ? "List is empty" : "List is not empty") << endl;*/

    list.clear();
    cout << "After clearing the list: ";
    list.printList();
    //cout << (list.empty() ? "List is empty" : "List is not empty") << endl;
    return 0;
}

