//원형 큐를 활용한 원형 버퍼
#include <iostream>
#include <stdexcept>

class CircularBuffer {
private:
    int* buffer;
    int capacity;
    int frontIndex;
    int rearIndex;
    int size;

public:
    CircularBuffer(int cap) : capacity(cap), frontIndex(0), rearIndex(-1), size(0) {
        buffer = new int[capacity];
    }

    ~CircularBuffer() {
        delete[] buffer;
    }

    void write(int data) {
        if (isFull()) throw std::overflow_error("Buffer is full!");
        rearIndex = (rearIndex + 1) % capacity;
        buffer[rearIndex] = data;
        size++;
    }

    int read() {
        if (isEmpty()) throw std::underflow_error("Buffer is empty!");
        int data = buffer[frontIndex];
        frontIndex = (frontIndex + 1) % capacity;
        size--;
        return data;
    }

    bool isFull() const {
        return size == capacity;
    }

    bool isEmpty() const {
        return size == 0;
    }
};

int main() {
    CircularBuffer buffer(3); // Capacity: 3
    buffer.write(1);
    buffer.write(2);
    buffer.write(3);

    std::cout << buffer.read() << "\n"; // 1
    buffer.write(4);
    std::cout << buffer.read() << "\n"; // 2
    std::cout << buffer.read() << "\n"; // 3
    std::cout << buffer.read() << "\n"; // 4

    return 0;
}
