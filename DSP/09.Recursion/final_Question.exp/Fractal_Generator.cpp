//프랙탈 생성
#include <iostream>
#include <string>

void generateFractal(int level, std::string current) {
    if (level == 0) {
        std::cout << current << "\n";
        return;
    }

    std::string next = "";
    for (char c : current) {
        if (c == '-') {
            next += "-┐└-";
        } else {
            next += c;
        }
    }
    generateFractal(level - 1, next);
}

int main() {
    int depth;
    std::cout << "Enter fractal depth: ";
    std::cin >> depth;

    generateFractal(depth, "-");
    return 0;
}
