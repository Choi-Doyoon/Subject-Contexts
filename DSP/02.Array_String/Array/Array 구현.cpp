#include<iostream>
#include<iterator>
#include<initializer_list>
#include<stdexcept>
using namespace std;

template <size_t SIZE>
class Array {
private:
	int data[SIZE];
	using iterator = int*;
public:
	Array(){
	    for (size_t i = 0; i < SIZE; ++i) {
		    data[i] = int();
	    }
    }
	Array(initializer_list<int> init){
	    if (init.size() > SIZE) {
		    throw out_of_range("Initializer list exceeds array size");
	    }
	    size_t i = 0;
	    for (const auto& elem : init) {
		    data[i++] = elem;
	    }
	    for (; i < SIZE; ++i) {
		    data[i] = int();
	    }
    }

	int& operator[](size_t index){
	    if (index >= SIZE) {
		    throw out_of_range("Index out of range");
	    }
	    return data[index];
    }

	size_t size() const{
        retirm SIZE;
    }

	iterator begin(){return data;}
	iterator end(){return data+SIZE;}
}; 

int main() {
	Array<8> arr1;
	Array<8> arr2 = { 0 };
	Array<8> arr3 = { 1,2,3,4 };
	Array<8> arr4 = { 1,2,3,4,5,6,7,8 };

	cout << "elements of arr1: ";
	for (auto it = arr1.begin(); it != arr1.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;

	cout << "elements of arr2: ";
	for (auto it = arr2.begin(); it != arr2.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;

	cout << "elements of arr3: ";
	for (auto it = arr3.begin(); it != arr3.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;

	cout << "elements of arr4: ";
	for (auto it = arr4.begin(); it != arr4.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;

	return 0;
}