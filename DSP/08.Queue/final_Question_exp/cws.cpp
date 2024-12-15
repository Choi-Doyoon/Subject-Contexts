//세차 시뮬레이션(퍼센트 포함) 구현
#include <iostream>
#include <queue>
#include <cstdlib>
#include <ctime>

class CarWash {
private:
    std::queue<int> carQueue;
    int totalWaitTime = 0;
    int totalCars = 0;
    int washTime;

public:
    CarWash(int washTime) : washTime(washTime) {}

    void simulate(int arrivalProbability, int simulationTime) {
        std::srand(std::time(0));
        for (int time = 0; time < simulationTime; ++time) {
            if (std::rand() % 100 < arrivalProbability) {
                carQueue.push(time);
                std::cout << "Car arrived at time " << time << "\n";
            }

            if (!carQueue.empty() && washTime == 0) {
                int arrivalTime = carQueue.front();
                carQueue.pop();
                totalWaitTime += (time - arrivalTime);
                totalCars++;
                washTime = 5; // Reset wash time
            }

            if (washTime > 0) {
                washTime--;
            }
        }

        std::cout << "Total cars washed: " << totalCars << "\n";
        std::cout << "Average wait time: " << (totalCars == 0 ? 0 : totalWaitTime / totalCars) << " seconds\n";
    }
};

int main() {
    CarWash carWash(0);
    carWash.simulate(30, 100); // 30% probability, 100 seconds simulation
    return 0;
}
