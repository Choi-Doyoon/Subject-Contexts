//완전 이진 트리인지 확인
#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

bool isCompleteTree(Node* root) {
    if (!root) return true;

    queue<Node*> q;
    q.push(root);

    bool end = false;
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        if (!current) {
            end = true;
        } else {
            if (end) return false;
            q.push(current->left);
            q.push(current->right);
        }
    }
    return true;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Is Complete Binary Tree: " << (isCompleteTree(root) ? "Yes" : "No") << endl; // Yes
    return 0;
}
