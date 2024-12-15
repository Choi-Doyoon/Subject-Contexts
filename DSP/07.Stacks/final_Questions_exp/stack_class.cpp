#include <iostream>

template <typename T>
class Stack {
private:
    T* data;
    int capacity;
    int topIndex;

    void resize(int newCapacity) {
        T* newData = new T[newCapacity];
        for (int i = 0; i <= topIndex; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    Stack(int initialCapacity = 10)
        : capacity(initialCapacity), topIndex(-1) {
        data = new T[capacity];
    }

    ~Stack() {
        delete[] data;
    }

    void push(const T& value) {
        if (topIndex + 1 == capacity) {
            resize(capacity * 2);
        }
        data[++topIndex] = value;
    }

    void pop() {
        if (!isEmpty()) {
            --topIndex;
        }
    }

    T top() const {
        if (!isEmpty()) {
            return data[topIndex];
        }
        throw std::out_of_range("Stack is empty!");
    }

    bool isEmpty() const {
        return topIndex == -1;
    }
};
