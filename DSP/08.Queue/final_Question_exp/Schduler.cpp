//우선순위 큐를 활용한 작업 스케줄러 구현
#include <iostream>
#include <queue>
#include <vector>
#include <string>

class TaskScheduler {
private:
    struct Task {
        int priority;
        std::string taskName;

        bool operator<(const Task& other) const {
            return priority < other.priority; // Higher priority comes first
        }
    };

    std::priority_queue<Task> taskQueue;

public:
    void addTask(int priority, const std::string& taskName) {
        taskQueue.push({priority, taskName});
    }

    void processTask() {
        if (taskQueue.empty()) {
            std::cout << "No tasks to process.\n";
            return;
        }
        Task task = taskQueue.top();
        taskQueue.pop();
        std::cout << "Processing task: " << task.taskName << "\n";
    }
};

int main() {
    TaskScheduler scheduler;
    scheduler.addTask(2, "Write report");
    scheduler.addTask(1, "Fix bug");
    scheduler.addTask(3, "Implement feature");

    scheduler.processTask(); // Implement feature
    scheduler.processTask(); // Write report
    scheduler.processTask(); // Fix bug

    return 0;
}
