#include<iostream>
#include<set>
using namespace std;

int main() {
	set<int> mySet = { 1,2,3,4,5 };

	cout << "My set is ";
	for (int elem : mySet) {
		cout << elem << " ";
	}
	cout << endl;

	mySet.insert(6);
	mySet.erase(3);

	if (mySet.find(4) != mySet.end()) {
		cout << "4 is in the set." << endl;
	}

	cout << "My set is ";
	for (int elem : mySet) {
		cout << elem << " ";
	}
	cout << endl;

	return 0;
}