//우선순위 큐 구현
#include <iostream>
#include <stdexcept>
#include <algorithm>

class PriorityQueue {
private:
    int* data;
    int capacity;
    int size;

public:
    PriorityQueue(int cap) : capacity(cap), size(0) {
        data = new int[capacity];
    }

    ~PriorityQueue() {
        delete[] data;
    }

    void insert(int x) {
        if (size == capacity) {
            throw std::overflow_error("Priority Queue is full!");
        }
        data[size] = x;
        size++;
        std::sort(data, data + size, std::greater<int>());
    }

    int extractMax() {
        if (size == 0) {
            throw std::underflow_error("Priority Queue is empty!");
        }
        int maxVal = data[0];
        for (int i = 1; i < size; i++) {
            data[i - 1] = data[i];
        }
        size--;
        return maxVal;
    }

    int peekMax() const {
        if (size == 0) {
            throw std::underflow_error("Priority Queue is empty!");
        }
        return data[0];
    }
};

int main() {
    PriorityQueue pq(3);
    pq.insert(10);
    pq.insert(5);
    pq.insert(20);

    std::cout << "Max: " << pq.extractMax() << "\n"; // 20
    std::cout << "Max: " << pq.peekMax() << "\n";   // 10

    return 0;
}
