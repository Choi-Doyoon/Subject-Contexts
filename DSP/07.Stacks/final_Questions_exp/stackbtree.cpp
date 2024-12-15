//스택으로 이진 트리 순회
#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

class Stack {
private:
    TreeNode** data;
    int topIndex;
    int capacity;

    void resize(int newCapacity) {
        TreeNode** newData = new TreeNode*[newCapacity];
        for (int i = 0; i <= topIndex; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    Stack(int initialCapacity = 10) : topIndex(-1), capacity(initialCapacity) {
        data = new TreeNode*[capacity];
    }

    ~Stack() {
        delete[] data;
    }

    void push(TreeNode* node) {
        if (topIndex + 1 == capacity) resize(2 * capacity);
        data[++topIndex] = node;
    }

    void pop() {
        if (topIndex >= 0) --topIndex;
        else throw std::out_of_range("Stack is empty!");
    }

    TreeNode* top() const {
        if (topIndex >= 0) return data[topIndex];
        throw std::out_of_range("Stack is empty!");
    }

    bool isEmpty() const {
        return topIndex == -1;
    }
};

std::vector<int> inOrderTraversal(TreeNode* root) {
    std::vector<int> result;
    Stack stack;
    TreeNode* current = root;

    while (!stack.isEmpty() || current) {
        while (current) {
            stack.push(current);
            current = current->left;
        }

        current = stack.top();
        stack.pop();
        result.push_back(current->val);
        current = current->right;
    }

    return result;
}

std::vector<int> preOrderTraversal(TreeNode* root) {
    std::vector<int> result;
    if (!root) return result;

    Stack stack;
    stack.push(root);

    while (!stack.isEmpty()) {
        TreeNode* node = stack.top();
        stack.pop();
        result.push_back(node->val);

        if (node->right) stack.push(node->right);
        if (node->left) stack.push(node->left);
    }

    return result;
}

std::vector<int> postOrderTraversal(TreeNode* root) {
    std::vector<int> result;
    if (!root) return result;

    Stack stack;
    TreeNode* prev = nullptr;
    stack.push(root);

    while (!stack.isEmpty()) {
        TreeNode* current = stack.top();
        if (!prev || prev->left == current || prev->right == current) {
            if (current->left) {
                stack.push(current->left);
            } else if (current->right) {
                stack.push(current->right);
            }
        } else if (current->left == prev) {
            if (current->right) stack.push(current->right);
        } else {
            result.push_back(current->val);
            stack.pop();
        }
        prev = current;
    }

    return result;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    std::vector<int> inOrder = inOrderTraversal(root);
    std::cout << "InOrder: ";
    for (int val : inOrder) std::cout << val << " ";
    std::cout << "\n";

    std::vector<int> preOrder = preOrderTraversal(root);
    std::cout << "PreOrder: ";
    for (int val : preOrder) std::cout << val << " ";
    std::cout << "\n";

    std::vector<int> postOrder = postOrderTraversal(root);
    std::cout << "PostOrder: ";
    for (int val : postOrder) std::cout << val << " ";
    std::cout << "\n";

    return 0;
}
