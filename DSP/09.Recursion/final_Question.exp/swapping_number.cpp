//숫자 뒤집기와 음수 처리
#include <iostream>

void reverseNumber(int number) {
    if (number < 0) {
        std::cout << "-";
        reverseNumber(-number);
        return;
    }

    if (number < 10) {
        std::cout << number;
        return;
    }

    std::cout << number % 10;
    reverseNumber(number / 10);
}

int main() {
    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;

    reverseNumber(number);
    std::cout << "\n";
    return 0;
}
