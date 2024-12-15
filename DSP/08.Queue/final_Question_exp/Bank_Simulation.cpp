//은행 시뮬레이션
#include <iostream>
#include <queue>

class BankSimulation {
private:
    struct Customer {
        int id;
        int processTime;

        Customer(int id, int time) : id(id), processTime(time) {}
    };

    std::queue<Customer> customerQueue;
    int totalWaitTime = 0;
    int totalCustomers = 0;

public:
    void addCustomer(int id, int processTime) {
        customerQueue.push(Customer(id, processTime));
    }

    void run() {
        int currentTime = 0;

        while (!customerQueue.empty()) {
            Customer currentCustomer = customerQueue.front();
            customerQueue.pop();

            std::cout << "Customer " << currentCustomer.id << " processed in " << currentCustomer.processTime << " seconds.\n";

            totalWaitTime += currentTime;
            currentTime += currentCustomer.processTime;
            totalCustomers++;
        }

        std::cout << "Total customers processed: " << totalCustomers << "\n";
        std::cout << "Average wait time: " << (totalCustomers == 0 ? 0 : static_cast<double>(totalWaitTime) / totalCustomers) << " seconds\n";
    }
};

int main() {
    BankSimulation simulation;
    simulation.addCustomer(1, 5);
    simulation.addCustomer(2, 3);
    simulation.addCustomer(3, 8);

    simulation.run();

    return 0;
}
