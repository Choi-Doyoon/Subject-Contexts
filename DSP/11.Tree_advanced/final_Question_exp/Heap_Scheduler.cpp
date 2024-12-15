//힙을 활용한 우선순위 작업 스케줄러
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class TaskScheduler {
private:
    struct Task {
        int priority;
        string name;

        bool operator<(const Task& other) const {
            return priority < other.priority;
        }
    };

    vector<Task> heap;

    void heapifyDown(int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < heap.size() && heap[left] < heap[largest]) {
            largest = left;
        }
        if (right < heap.size() && heap[right] < heap[largest]) {
            largest = right;
        }
        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }

    void heapifyUp(int i) {
        int parent = (i - 1) / 2;
        if (i > 0 && heap[i] < heap[parent]) {
            swap(heap[i], heap[parent]);
            heapifyUp(parent);
        }
    }

public:
    void addTask(int priority, const string& name) {
        heap.push_back({priority, name});
        heapifyUp(heap.size() - 1);
    }

    void processTask() {
        if (heap.empty()) {
            cout << "No tasks to process." << endl;
            return;
        }

        Task topTask = heap.front();
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);

        cout << "Processing Task: " << topTask.name << " (Priority: " << topTask.priority << ")" << endl;
    }
};

int main() {
    TaskScheduler scheduler;
    scheduler.addTask(5, "Task A");
    scheduler.addTask(2, "Task B");
    scheduler.addTask(8, "Task C");
    scheduler.addTask(6, "Task D");

    scheduler.processTask();
    scheduler.processTask();
    scheduler.processTask();
    scheduler.processTask();

    return 0;
}
