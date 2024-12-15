//히스토그램에서 가장 큰 직사각형 찾기
#include <iostream>
#include <vector>
#include <stdexcept>

class Stack {
private:
    int* data;
    int topIndex;
    int capacity;

    void resize(int newCapacity) {
        int* newData = new int[newCapacity];
        for (int i = 0; i <= topIndex; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    Stack(int initialCapacity = 10) : topIndex(-1), capacity(initialCapacity) {
        data = new int[capacity];
    }

    ~Stack() {
        delete[] data;
    }

    void push(int x) {
        if (topIndex + 1 == capacity) resize(2 * capacity);
        data[++topIndex] = x;
    }

    void pop() {
        if (topIndex >= 0) --topIndex;
        else throw std::out_of_range("Stack is empty!");
    }

    int top() const {
        if (topIndex >= 0) return data[topIndex];
        throw std::out_of_range("Stack is empty!");
    }

    bool isEmpty() const {
        return topIndex == -1;
    }
};

int largestRectangleArea(const std::vector<int>& heights) {
    Stack stack;
    int maxArea = 0;
    int i = 0;

    while (i < heights.size()) {
        if (stack.isEmpty() || heights[stack.top()] <= heights[i]) {
            stack.push(i++);
        } else {
            int top = stack.top();
            stack.pop();
            int height = heights[top];
            int width = stack.isEmpty() ? i : i - stack.top() - 1;
            maxArea = std::max(maxArea, height * width);
        }
    }

    while (!stack.isEmpty()) {
        int top = stack.top();
        stack.pop();
        int height = heights[top];
        int width = stack.isEmpty() ? i : i - stack.top() - 1;
        maxArea = std::max(maxArea, height * width);
    }

    return maxArea;
}

int main() {
    std::vector<int> heights = {2, 1, 5, 6, 2, 3};
    std::cout << "Largest Rectangle: " << largestRectangleArea(heights) << "\n"; // 10
    return 0;
}
