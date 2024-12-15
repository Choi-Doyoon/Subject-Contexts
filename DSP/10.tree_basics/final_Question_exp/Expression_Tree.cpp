//수식 트리 평가
#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* left;
    Node* right;

    Node(string val) : data(val), left(nullptr), right(nullptr) {}
};

int evaluate(Node* root) {
    if (!root->left && !root->right) return stoi(root->data);

    int leftVal = evaluate(root->left);
    int rightVal = evaluate(root->right);

    if (root->data == "+") return leftVal + rightVal;
    if (root->data == "-") return leftVal - rightVal;
    if (root->data == "*") return leftVal * rightVal;
    if (root->data == "/") return leftVal / rightVal;

    return 0;
}

int main() {
    Node* root = new Node("+");
    root->left = new Node("*");
    root->right = new Node("5");
    root->left->left = new Node("4");
    root->left->right = new Node("3");

    cout << "Result: " << evaluate(root) << endl; // 17
    return 0;
}
