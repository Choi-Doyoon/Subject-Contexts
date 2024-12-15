#include<iostream>
#include<vector>
#include<queue>
using namespace std;

template <typename T >

class my_priority_queue {							
private:
	int p_size;
	vector<T> v;
public:
	my_priority_queue() {
		p_size = 0;
		v.push_back(0);							
	}
	void push(const T& elem) {
		v.push_back(elem);						

		if (empty()) {							
			v[p_size] = elem;
		}

		int idx = v.size() - 1, parent = 0, child = 0;	
		while (idx > 1) {						
			// ���� 1-1 �ۼ�, 3�� (Problem 1-1, 3pts)
			for(idx=2;idx<v.size();idx++){
                v[idx-1]=elem;
            }
		}
		p_size++;

	}
	void heapify(const int& idx) {					
		// ���� 1-2 �ۼ�, 4�� (Problem 1-2, 4pts)
		int parent = (idx - 1) / 2;
		int largest = idx;
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;
        if (idx > 0 && v[idx] > v[parent]) {
            swap(v[idx], v[parent]);
            heapify(parent);
        }
		if (left < v.size() && v[left] > v[largest]) {
            largest = left;
        }
        if (right < v.size() && v[right] > v[largest]) {
            largest = right;
        }
        if (largest != idx) {
            swap(v[idx], v[largest]);
            heapify(largest);
        }
	}
	void pop() {
		if (empty()) {
			cout << "Empty priority queue!";
			return;
		}
		swap(v[1], v[v.size() - 1]);			
		v.pop_back();							
		heapify(1);
		p_size--;
	}

	T top() {
		return v[1];
	}

	int size() {
		return p_size;
	}

	bool empty() {
		if (p_size) return false;
		else return true;
	}
};

int main() {
	my_priority_queue<int> mpq;
	priority_queue<int> pq;

	cout << "STL priority queue" << endl;

	pq.push(4);
	pq.push(7);
	pq.push(3);
	pq.push(1);
	pq.push(10);

	cout << "push 5 elements and excute the top method" << endl;
	cout << pq.top() << endl;

	cout << "pop 3 elements and excute the top method" << endl;

	pq.pop();
	cout << pq.top() << endl; // pop 1 
	pq.pop();
	cout << pq.top() << endl; // pop 2
	pq.pop();
	cout << pq.top() << endl; // pop 3

	cout << "size of the priority queue" << endl;
	cout << pq.size() << endl;

	cout << "my priority queue" << endl;

	mpq.push(4);
	mpq.push(7);
	mpq.push(3);
	mpq.push(1);
	mpq.push(10);

	cout << "push 5 elements and excute the top method" << endl;
	cout << mpq.top() << endl;

	cout << "pop 3 elements and excute the top method" << endl;

	mpq.pop();
	cout << mpq.top() << endl; // pop 1
	mpq.pop();
	cout << mpq.top() << endl; // pop 2
	mpq.pop();
	cout << mpq.top() << endl; // pop 3

	cout << "size of the priority queue" << endl;
	cout << mpq.size() << endl;

}