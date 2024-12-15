//스택을 사용한 중위 표현식 계산기
#include <iostream>
#include <sstream>
#include <cctype>
#include <string>
#include <stdexcept>

class Stack {
private:
    char* data;
    int topIndex;
    int capacity;

    void resize(int newCapacity) {
        char* newData = new char[newCapacity];
        for (int i = 0; i <= topIndex; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    Stack(int initialCapacity = 10) : topIndex(-1), capacity(initialCapacity) {
        data = new char[capacity];
    }

    ~Stack() {
        delete[] data;
    }

    void push(char x) {
        if (topIndex + 1 == capacity) resize(2 * capacity);
        data[++topIndex] = x;
    }

    void pop() {
        if (topIndex >= 0) --topIndex;
        else throw std::out_of_range("Stack is empty!");
    }

    char top() const {
        if (topIndex >= 0) return data[topIndex];
        throw std::out_of_range("Stack is empty!");
    }

    bool isEmpty() const {
        return topIndex == -1;
    }
};

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

std::string infixToPostfix(const std::string& infix) {
    std::string postfix;
    Stack stack;

    for (char c : infix) {
        if (std::isspace(c)) continue;

        if (std::isdigit(c)) {
            postfix += c;
        } else if (c == '(') {
            stack.push(c);
        } else if (c == ')') {
            while (!stack.isEmpty() && stack.top() != '(') {
                postfix += stack.top();
                stack.pop();
            }
            stack.pop();
        } else {
            while (!stack.isEmpty() && precedence(stack.top()) >= precedence(c)) {
                postfix += stack.top();
                stack.pop();
            }
            stack.push(c);
        }
    }

    while (!stack.isEmpty()) {
        postfix += stack.top();
        stack.pop();
    }

    return postfix;
}

int evaluatePostfix(const std::string& postfix) {
    Stack stack;

    for (char c : postfix) {
        if (std::isdigit(c)) {
            stack.push(c - '0');
        } else {
            int b = stack.top(); stack.pop();
            int a = stack.top(); stack.pop();
            switch (c) {
                case '+': stack.push(a + b); break;
                case '-': stack.push(a - b); break;
                case '*': stack.push(a * b); break;
                case '/': stack.push(a / b); break;
            }
        }
    }

    return stack.top();
}

int evaluateInfix(const std::string& infix) {
    std::string postfix = infixToPostfix(infix);
    return evaluatePostfix(postfix);
}

int main() {
    std::string expression = "3 + 5 * ( 2 - 8 )";
    std::cout << "Result: " << evaluateInfix(expression) << "\n"; // -27
    return 0;
}
