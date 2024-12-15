//하노이 탑
#include <iostream>

void hanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        std::cout << "Move disk 1 from " << from << " to " << to << "\n";
        return;
    }

    hanoi(n - 1, from, aux, to);
    std::cout << "Move disk " << n << " from " << from << " to " << to << "\n";
    hanoi(n - 1, aux, to, from);
}

int main() {
    int n;
    std::cout << "Enter the number of disks: ";
    std::cin >> n;

    hanoi(n, 'A', 'C', 'B');
    return 0;
}
