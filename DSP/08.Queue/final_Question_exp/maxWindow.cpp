//데이터 스트림의 슬라이딩 윈도우 최댓값
#include <iostream>
#include <deque>
#include <vector>

class SlidingWindowMax {
private:
    std::deque<int> window;
    int size;

public:
    SlidingWindowMax(int k) : size(k) {}

    void add(int value) {
        while (!window.empty() && window.back() < value) {
            window.pop_back();
        }
        window.push_back(value);

        if (window.size() > size) {
            window.pop_front();
        }
    }

    int getMax() const {
        if (window.empty()) throw std::underflow_error("Window is empty!");
        return window.front();
    }
};

int main() {
    SlidingWindowMax window(3);
    window.add(1);
    window.add(3);
    window.add(-1);
    std::cout << window.getMax() << "\n"; // 3
    window.add(5);
    std::cout << window.getMax() << "\n"; // 5
    window.add(4);
    std::cout << window.getMax() << "\n"; // 5

    return 0;
}
