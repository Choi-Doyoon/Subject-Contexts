//파스칼 삼각형 생성
#include <iostream>

int pascal(int row, int col) {
    if (col == 0 || col == row) return 1;
    return pascal(row - 1, col - 1) + pascal(row - 1, col);
}

void generatePascal(int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j <= i; j++) {
            std::cout << pascal(i, j) << " ";
        }
        std::cout << "\n";
    }
}

int main() {
    int rows;
    std::cout << "Enter number of rows: ";
    std::cin >> rows;

    generatePascal(rows);
    return 0;
}
