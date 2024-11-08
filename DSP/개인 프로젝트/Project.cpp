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

    // �迭 ũ�� ������ ���� �޼���
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
    // ����� �Է��� ���� �ʱ� �뷮 ����
    Refrigerator(int initialCapacity) : capacity(initialCapacity), size(0) {
        ingredients = new string[capacity];
        quantities = new int[capacity];
    }

    ~Refrigerator() {
        delete[] ingredients;
        delete[] quantities;
    }

    void addIngredient(const string& name, int quantity) {
        // �뷮 �ʰ� �� �迭 ũ�� ����
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
        cout << "����� ���빰:" << endl;
        for (int i = 0; i < size; ++i) {
            cout << "����: " << ingredients[i] << ", ����: " << quantities[i] << endl;
        }
        if(quantities[size]>capacity){
            cout<<"����� �뷮 �ʰ�."<<endl;
        }
    }
};

int main() {
    int initialCapacity;
    cout << "����� �뷮�� �Է��ϼ���: ";
    cin >> initialCapacity;

    Refrigerator fridge(initialCapacity);

    // ����ڰ� ����� ������ �Է�
    while (true) {
        string name;
        int quantity;
        cout << "������ �Է��ϼ��� (�����Ϸ��� 'exit' �Է�): ";
        cin >> name;
        if (name == "exit") break;

        cout << "������ �Է��ϼ���: ";
        cin >> quantity;

        fridge.addIngredient(name, quantity);

        // ���� ����� ���� ���
        fridge.displayContents();
    }

    return 0;
}
