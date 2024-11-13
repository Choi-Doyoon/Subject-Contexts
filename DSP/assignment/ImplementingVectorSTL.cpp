#include <cstdlib>
#include <algorithm>
#include <iterator> //반복자 사용을 위함
#include <iostream> //c++ 라이브러리
using namespace std;

class MakeVector {
private:
    int* data;
    size_t used, space; //크기, 용량 메서드에 사용할 변수
public:
    using iterator = int*; //반복자 주소 사용
    // 생성자
    MakeVector(int size) : used(size), space(size), data(new int[size]) {
        size_t i = 0;
        while (i < used) {
            data[i] = int();  // 배열을 초기화
            ++i;
        }
    }
    ~MakeVector() { delete[] data; } //소멸자

    size_t size() const { return used; } //크기
    size_t capacity() const { return space; } //용량

    void reserve(size_t n) {
        if (n == capacity()) { return; }
        if (n < size()) { n = size(); }
        int* answer = new int[n];
        copy(data, data + size(), answer);
        delete[] data;
        data = answer;
        space = n;
    }
    bool is_empty() const { //배열이 비었는지 확인
        if (size() == 0) {
            return true;
        }
        else {
            return false;
        }
    }

    void push_back(const int& x) {
        if (used == capacity()) { reserve(size() + 3); } //용량 조정
        data[used] = x;
        used++; //크기 증가
    }
    void pop_back() {
        if (!is_empty()) { used--; } //크기 감소
    }

    MakeVector& operator=(const MakeVector& v) {
        if (this == &v) { return *this; }
        if (capacity() != v.capacity()) {
            delete[] data;
            data = new int[v.capacity()];
            space = v.capacity();
        }
        used = v.size();
        copy(v.data, v.data + used, data); //배열 수정 시 데이터 복사
        return *this;
    }

    int& operator[](int n) {
        if (n >= size()) {
            cout << "Vector::operator[]: index " << n << " out of range" << endl;
            exit(100);
        }
        return data[n];
    }
    //반복자
    iterator begin() { return data; }
    iterator end() { return data + used; }
};

int main() {
    MakeVector v(3); //클래스를 이용한 선언
    MakeVector::iterator it; //반복자 선언

    cout << "size of v: " << v.size() << endl;
    cout << "capacity of v: " << v.capacity() << endl;
    cout << "elements of v: ";
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl << endl;

    for (size_t i = 0; i < v.size(); ++i) {
        v[i] = i + 1;
    }
    for (int i = 10; i < 15; ++i) {
        v.push_back(i);
    }

    cout << "--- After push_back ---" << endl;
    cout << "size of v: " << v.size() << endl;
    cout << "capacity of v: " << v.capacity() << endl;
    cout << "elements of v: ";
    for (it = v.begin(); it != v.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl << endl;

    v.pop_back();
    v.pop_back();

    cout << "--- After pop_back ---" << endl;
    cout << "size of v: " << v.size() << endl;
    cout << "capacity of v: " << v.capacity() << endl;
    cout << "elements of v: ";
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}
