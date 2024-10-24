#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class set{
    private:
    using iterator = typename vector<int>::iterator;
    using const_iterator = typename vector<int>::const_iterator;
    vector<int> data;
    public:
    set() {
        data.resize(5);
        data.clear();
    }

    ~set(){}

    void resize(size_t newCapacity){
        if(newCapacity<data.size()){
            newCapacity=data.size();
        }
        else{
            data.resize(newCapacity);
        }
    }
    
    void insert(int value) {
		if (!contains(value)) {
			data.push_back(value);
			sort(data.begin(), data.end());
		}
	}

    bool contains(int value){
        return find(value) != end();
    }

    void erase(int value) {
		auto it = std::find(data.begin(), data.end(), value);
		if (it != data.end()) {
			data.erase(it);
		}
        else{
            cout<<"The value does not exist."<<endl;
        }
	}

    void printSet(){
        for(int i=0;i<data.size();i++){
            cout<<" "<<data[i];
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
};

int main(){
    set Set;
    Set.insert(1);
    Set.insert(2);
    Set.insert(3);
    Set.insert(4);
    Set.insert(5);

    cout<<"My set is: ";
    Set.printSet();
    cout<<endl;
    Set.insert(6);
    cout<<"After inserting 6: ";
    Set.printSet();
    cout<<endl;
    Set.erase(7);
    Set.erase(3);
    cout<<"After erasing 3: ";
    Set.printSet();
    cout<<endl;
    cout<<"Contains 4? "<<(Set.contains(4) ? "Yes" : "No")<<endl;
    cout<<"Contains 7? "<<(Set.contains(7) ? "Yes" : "No")<<endl;
    Set.erase(7);
    return 0;
}