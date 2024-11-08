#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

class Refrigerator {
private:
    string* ingredients;
    int* quantities;
    int capacity;
    int size;

    // 배열 크기 조정을 위한 메서드
    void resize(int newCapacity) {
        string* newIngredients = new string[newCapacity];
        int* newQuantities = new int[newCapacity];

        for (int i = 0; i < size; ++i) {
            newIngredients[i] = ingredients[i];
            newQuantities[i] = quantities[i];
        }
        
        delete[] ingredients;
        delete[] quantities;

        ingredients = newIngredients;
        quantities = newQuantities;
        capacity = newCapacity;
    }

public:
    // 사용자 입력을 통해 초기 용량 설정
    Refrigerator(int initialCapacity) : capacity(initialCapacity), size(0) {
        ingredients = new string[capacity];
        quantities = new int[capacity];
    }

    ~Refrigerator() {
        delete[] ingredients;
        delete[] quantities;
    }

    void addIngredient(const string& name, int quantity) {
        // 용량 초과 시 배열 크기 조정
        if (size == capacity) {
            resize(capacity * 2);
        }
        ingredients[size] = name;
        quantities[size] = quantity;
        size++;
    }

    void removeIngredient() {
        if (size > 0) {
            --size;
        } else {
            throw out_of_range("Refrigerator is empty.");
        }
    }

    int current_capacity() const { return capacity; }
    int current_size() const { return size; }

    void displayContents() const {
        cout << "냉장고 내용물:" << endl;
        for (int i = 0; i < size; ++i) {
            cout << "재료명: " << ingredients[i] << ", 수량: " << quantities[i] << endl;
        }
        if(quantities[size]>capacity){
            cout<<"냉장고 용량 초과."<<endl;
        }
    }
};

int main() {
    int initialCapacity;
    cout << "냉장고 용량을 입력하세요: ";
    cin >> initialCapacity;

    Refrigerator fridge(initialCapacity);

    // 사용자가 재료명과 개수를 입력
    while (true) {
        string name;
        int quantity;
        cout << "재료명을 입력하세요 (종료하려면 'exit' 입력): ";
        cin >> name;
        if (name == "exit") break;

        cout << "수량을 입력하세요: ";
        cin >> quantity;

        fridge.addIngredient(name, quantity);

        // 현재 냉장고 내용 출력
        fridge.displayContents();
    }

    return 0;
}
