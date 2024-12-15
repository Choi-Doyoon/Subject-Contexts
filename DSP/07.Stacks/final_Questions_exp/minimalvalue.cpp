//최소값 지원 스택 구현
#include <iostream>
#include <stdexcept>

class MinStack {
private:
    struct Node {
        int value;
        int min;
        Node* next;
    };

    Node* topNode;

public:
    MinStack() : topNode(nullptr) {}

    ~MinStack() {
        while (topNode) {
            Node* temp = topNode;
            topNode = topNode->next;
            delete temp;
        }
    }

    void push(int x) {
        if (!topNode) {
            topNode = new Node{x, x, nullptr};
        } else {
            topNode = new Node{x, std::min(x, topNode->min), topNode};
        }
    }

    void pop() {
        if (!topNode) throw std::out_of_range("Stack is empty");
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }

    int top() const {
        if (!topNode) throw std::out_of_range("Stack is empty");
        return topNode->value;
    }

    int getMin() const {
        if (!topNode) throw std::out_of_range("Stack is empty");
        return topNode->min;
    }
};

int main() {
    MinStack stack;
    stack.push(3);
    stack.push(5);
    std::cout << "Min: " << stack.getMin() << "\n"; // 3
    stack.push(2);
    stack.push(1);
    std::cout << "Min: " << stack.getMin() << "\n"; // 1
    stack.pop();
    std::cout << "Min: " << stack.getMin() << "\n"; // 2
    return 0;
}
