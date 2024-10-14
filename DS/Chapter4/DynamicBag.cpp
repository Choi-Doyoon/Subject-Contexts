#include<iostream>
#include<cstdlib>
#include "DynamicBag.h"
using namespace std;
using namespace DB;

int main() {
    // 기본 용량을 가진 bag 객체 생성
    bag myBag(10);

    // bag에 값 추가
    myBag.insert(1);
    myBag.insert(2);
    myBag.insert(3);
    myBag.insert(2);  // 중복된 값 추가

    cout << "Bag size after inserts: " << myBag.size() << endl; // 4

    // 특정 값의 개수 확인
    cout << "Count of 2: " << myBag.count(2) << endl; // 2

    // 하나의 값을 제거
    bool erased = myBag.erase_one(2);
    if (erased) 
    {
        cout << "One occurrence of 2 erased. New count: " << myBag.count(2) << endl;
    }
    else 
    {
        cout << "Value 2 not found in the bag." << endl;
    }

    // 전체 값을 제거
    size_t numErased = myBag.erase(3);
    cout << "Number of 3's erased: " << numErased << endl;
    cout << "Bag size after erasing 3: " << myBag.size() << endl;

    // 새로운 bag 생성 후 병합
    bag anotherBag(10);
    anotherBag.insert(5);
    anotherBag.insert(6);

    myBag += anotherBag;
    cout << "Bag size after adding anotherBag: " << myBag.size() << endl; // 5

    // bag 객체끼리 더하기 연산
    bag combinedBag = myBag + anotherBag;
    cout << "Combined bag size: " << combinedBag.size() << endl; // 7

    return 0;
}
