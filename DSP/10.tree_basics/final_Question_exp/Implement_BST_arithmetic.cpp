//BST 구현 및 다양한 연산
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;

    Node* insert(Node* node, int data) {
        if (!node) return new Node(data);
        if (data < node->data)
            node->left = insert(node->left, data);
        else
            node->right = insert(node->right, data);
        return node;
    }

    Node* findMin(Node* node) {
        while (node->left) node = node->left;
        return node;
    }

    Node* remove(Node* node, int data) {
        if (!node) return nullptr;
        if (data < node->data)
            node->left = remove(node->left, data);
        else if (data > node->data)
            node->right = remove(node->right, data);
        else {
            if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            } else {
                Node* temp = findMin(node->right);
                node->data = temp->data;
                node->right = remove(node->right, temp->data);
            }
        }
        return node;
    }

    void inOrder(Node* node) {
        if (!node) return;
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }

    int findMinValue(Node* node) {
        while (node->left) node = node->left;
        return node->data;
    }

    int findMaxValue(Node* node) {
        while (node->right) node = node->right;
        return node->data;
    }

public:
    BST() : root(nullptr) {}

    void insert(int data) { root = insert(root, data); }

    void remove(int data) { root = remove(root, data); }

    void inOrder() {
        inOrder(root);
        cout << endl;
    }

    int findMin() { return findMinValue(root); }

    int findMax() { return findMaxValue(root); }
};

int main() {
    BST tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    cout << "In-order Traversal: ";
    tree.inOrder(); // 20 30 40 50 60 70 80

    tree.remove(50);

    cout << "After Deletion of 50: ";
    tree.inOrder(); // 20 30 40 60 70 80

    cout << "Min Value: " << tree.findMin() << endl; // 20
    cout << "Max Value: " << tree.findMax() << endl; // 80

    return 0;
}
