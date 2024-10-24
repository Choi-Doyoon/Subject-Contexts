#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Set {
private:
	using iterator = typename vector<int>::iterator;
	using const_iterator = typename vector<int>::const_iterator;
	vector<int> data;
public:
	Set() {}
	Set(initializer_list<int> init) {
		for (const auto& elem : init) {
			insert(elem);
		}
	}

	void insert(int value) {
		if (!contains(value)) {
			data.push_back(value);
			sort(data.begin(), data.end());
		}
	}

	bool contains(int value) {
		return find(value) != end();
	}

	void erase(int value) {
		auto it = std::find(data.begin(), data.end(), value);
		if (it != data.end()) {
			data.erase(it);
		}
	}

	iterator begin() {
		return data.begin();
	}
	iterator end() {
		return data.end();
	}
	const_iterator find(const int& val) {
		auto it = lower_bound(data.begin(), data.end(), val);
		if (it != data.end() && *it == val) {
			return it;
		}
		return end();
	}
	iterator lower_bound(iterator first, iterator last, const int& value)const {
		while (first < last) {
			iterator mid = first + (last - first) / 2;
			if (*mid < value) {
				first = mid + 1;
			}
			else {
				last = mid;
			}
		}
		return first;
	}
};

int main() {
	Set mySet = { 1,2,3,4,5 };

	cout << "My set is ";
	for (auto elem : mySet) {
		cout << elem << " ";
	}
	cout << endl;

	mySet.insert(6);
	mySet.erase(3);

	if (mySet.find(4) != mySet.end()) {
		cout << "4 is in the set." << endl;
	}

	cout << "My set is ";
	for (auto elem : mySet) {
		cout << elem << " ";
	}
	cout << endl;

	return 0;
}