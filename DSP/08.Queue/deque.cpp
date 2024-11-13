#include <iostream>
#include <stdexcept>

template <typename T>
class LinkedListDeque {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;

        Node(T value) : data(value), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int size;

public:
    LinkedListDeque() : head(nullptr), tail(nullptr), size(0) {}

    ~LinkedListDeque() {
        while (!isEmpty()) {
            removeFirst();
        }
    }

    bool isEmpty() const {
        return size == 0;
    }

    int getSize() const {
        return size;
    }

    void addFirst(const T& data) {
        Node* newNode = new Node(data);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    void addLast(const T& data) {
        Node* newNode = new Node(data);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    T removeFirst() {
        if (isEmpty()) {
            throw std::runtime_error("Deque is empty");
        }
        Node* temp = head;
        T data = temp->data;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
        size--;
        return data;
    }

    T removeLast() {
        if (isEmpty()) {
            throw std::runtime_error("Deque is empty");
        }
        Node* temp = tail;
        T data = temp->data;
        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }
        delete temp;
        size--;
        return data;
    }

    T getFirst() const {
        if (isEmpty()) {
            throw std::runtime_error("Deque is empty");
        }
        return head->data;
    }

    T getLast() const {
        if (isEmpty()) {
            throw std::runtime_error("Deque is empty");
        }
        return tail->data;
    }
};

int main() {
    LinkedListDeque<int> deque;

    deque.addFirst(10);
    deque.addLast(20);
    deque.addFirst(5);

    std::cout << "First: " << deque.getFirst() << std::endl;
    std::cout << "Last: " << deque.getLast() << std::endl;

    deque.removeFirst();
    deque.removeLast();

    std::cout << "First after removals: " << deque.getFirst() << std::endl;

    return 0;
}
