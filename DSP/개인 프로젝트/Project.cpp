#include<iostream>
#include<vector>
#include<stack>
#include<unordered_set>
#include<list>
#include<string>
using namespace std;

class Food{
public:
    string name; //재료이름
    int quantity; //재료 양
    //생성자
    Food(const string& name, int quantity){
        string name=name;
        int quantity=quantity;
    }
};

class refrigerator{
private:
    int maxcapacity; //냉장고 최대 용량
    int currentcapacity; //냉장고 현재 용량
    list<Food> orders;
    unordered_set<string> foodset;
public:
    //생성자
    refrigerator(int capacity){
        int maxcapacity=capacity;
        int currentcapacity=0; 
    }

    bool addItem(const string& name,int quantity){
        if(currentcapacity+quantity>maxcapacity){
            cout<<"Not enough space for "<<name<<" ("<<quantity<<" units)\n";
            return false;
        }

        if(foodset.find(name) == foodset.end()){
            foodset.insert(name);
        }

        orders.push_back(Food(name, quantity));
        currentcapacity += quantity;

        displaycurrentstatus();

        return true;
    }

    void displaycurrentstatus() const{
        cout<<"Current capacity: "<<currentcapacity<<"/" << maxcapacity<<"\n";
        cout<<"Items in the Refrigerator:\n";
        for(const auto &Food : orders){
            cout<<"- "<<Food.name<<": "<<Food.quantity<<" units\n";
        }
    }

    void displayfinalorder(){ //마지막 결과물 확인
        cout<<"\nFinal order summanry:\n";
        list<Food> orderlist;
        while(!orders.empty()){
            orderlist.push_front(orders.back());
            orders.pop_back();
        }
        for(const auto &Food: orderlist){
            cout<<"- "<<Food.name<<": "<<Food.quantity<<" units\n";
        }
    }
};