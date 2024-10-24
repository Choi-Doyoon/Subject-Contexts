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
	bool is_subset(Set other) const {
		for (const auto& elem : data) {
			if (!other.contains(elem)) {
				return false;
			}
		}
		return true;
	}
};
Set set_union(Set set1, Set set2) {
	Set result = set1;
	for (const auto elem : set2) {
		result.insert(elem);
	}
	return result;
}

Set set_intersection(Set set1, Set set2) {
	Set result;
	for (const auto& elem : set1) {
		if (set2.contains(elem)) {
			result.insert(elem);
		}
	}
	return result;
}

Set set_difference(Set set1, Set set2) {
	Set result;
	for (const auto& elem : set1) {
		if (!set2.contains(elem)) {
			result.insert(elem);
		}
	}
	return result;
}

int main() {
	Set set1 = { 1,2,3,4,5 };
	Set set2 = { 4,5,6,7,8 };

	cout << "Set1: ";
	for (auto elem : set1) {
		cout << elem << " ";
	}
	cout << endl;

	cout << "Set2: ";
	for (auto elem : set2) {
		cout << elem << " ";
	}
	cout << endl;

	cout << "Union: ";
	Set union_set = set_union(set1, set2);
	for (auto elem : union_set) {
		cout << elem << " ";
	}
	cout << endl;

	cout << "Intersection: ";
	Set intersection_set = set_intersection(set1, set2);
	for (auto elem : intersection_set) {
		cout << elem << " ";
	}
	cout << endl;

	cout << "Difference (Set1-Set2): ";
	Set difference_set = set_difference(set1, set2);
	for (auto elem : difference_set) {
		cout << elem << " ";
	}
	cout << endl;

	cout << "Is Set1 a subset of Set2?" << (set1.is_subset(set2) ? "Yes" : "No") << endl;
	
	Set set3 = { 1,2 };
	cout << "Set3: ";
	for (auto elem : set3) {
		cout << elem << " ";
	}
	cout << endl;

	cout << "Is Set3 a subset of Set1?" << (set3.is_subset(set1) ? "Yes" : "No") << endl;
	return 0;
}