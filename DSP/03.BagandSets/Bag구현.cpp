#include<iostream>
#include<algorithm>
#include<cassert>
using namespace std;

class Bag {
public:
	static const size_t CAPACITY = 20;
	Bag() :used(0), data() {}
	void insert(const int& entry){
		assert(size() < CAPACITY);
		data[used++] = entry;
	}
	bool erase_one(const int& target) {
		int index = 0;
		while ((index < used) && (data[index] != target))
			++index;
		if (index == used)
			return false;
		--used;
		data[index] = data[used];
		return true;
	}
	size_t size() const { return used; }

	int operator[](size_t i) const { return data[i]; }
	void operator+=(const Bag& addend) {
		assert(size() + addend.size() <= CAPACITY);
		copy(addend.data, addend.data + addend.used, data + used);
		used += addend.used;
	}
private:
	int data[CAPACITY];
	size_t used;
};

int main() {
	Bag bag1;
	bag1.insert(1);
	bag1.insert(2);
	bag1.insert(1);

	cout << "bag1: ";
	for (size_t i = 0; i < bag1.size(); i++) {
		cout << bag1[i] << " ";
	}
	cout << endl << endl;

	Bag bag2;
	bag2.insert(4);
	bag2.insert(1);
	bag2.insert(6);
	cout << "bag2: ";
	for (size_t i = 0; i < bag2.size(); i++) {
		cout << bag2[i] << " ";
	}
	cout << endl << endl;

	bag2 += bag1;

	cout << "bag2: ";
	for (size_t i = 0; i < bag2.size(); i++) {
		cout << bag2[i] << " ";
	}
	cout << endl << endl;

	return 0;
}