//최소 비용으로 문자열 뒤집기
#include <iostream>
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

int minCostToMakeValid(const std::string& str) {
    Stack stack;
    int unmatchedLeft = 0, unmatchedRight = 0;

    for (char c : str) {
        if (c == '{') {
            stack.push(c);
        } else if (c == '}') {
            if (stack.isEmpty()) {
                unmatchedRight++;
            } else {
                stack.pop();
            }
        }
    }

    while (!stack.isEmpty()) {
        unmatchedLeft++;
        stack.pop();
    }

    // Each unmatched pair requires 1 flip to fix.
    return (unmatchedLeft + unmatchedRight) / 2;
}

int main() {
    std::string input = "}{{}}{{";
    std::cout << "Min Cost: " << minCostToMakeValid(input) << "\n"; // 2
    return 0;
}
