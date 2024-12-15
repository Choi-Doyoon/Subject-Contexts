//원형 큐 구현
#include <iostream>
#include <stdexcept>

class CircularQueue {
private:
    int* data;
    int frontIndex;
    int rearIndex;
    int capacity;
    int size;

public:
    CircularQueue(int cap) : capacity(cap), frontIndex(0), rearIndex(-1), size(0) {
        data = new int[capacity];
    }

    ~CircularQueue() {
        delete[] data;
    }

    void enqueue(int x) {
        if (isFull()) {
            throw std::overflow_error("Queue is full!");
        }
        rearIndex = (rearIndex + 1) % capacity;
        data[rearIndex] = x;
        size++;
    }

    void dequeue() {
        if (isEmpty()) {
            throw std::underflow_error("Queue is empty!");
        }
        frontIndex = (frontIndex + 1) % capacity;
        size--;
    }

    int front() const {
        if (isEmpty()) {
            throw std::underflow_error("Queue is empty!");
        }
        return data[frontIndex];
    }

    bool isEmpty() const {
        return size == 0;
    }

    bool isFull() const {
        return size == capacity;
    }
};

int main() {
    CircularQueue q(3);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    std::cout << "Front: " << q.front() << "\n"; // 10
    q.dequeue();
    std::cout << "Front: " << q.front() << "\n"; // 20

    q.enqueue(40);
    std::cout << "Front: " << q.front() << "\n"; // 20

    return 0;
}
