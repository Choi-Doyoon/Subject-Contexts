#include<iostream>
#include<vector>
using namespace std;

template<typename T>
class MaxHeap{
private:
    vector<T> heap;

    void reheapificate_upward(int index){
        if(index==1){
            return;
        }

        int parent = index/2;

        if(heap[index]>heap[parent]){
            swap(heap[index],heap[parent]);
            reheapificate_upward(parent);
        }
        else{
            return;
        }
    }

    void reheapificate_downward(int index){
        int left_child=2*index;
        int right_child=2*index+1;
        int larger_child;

        if(left_child>=heap.size()){
            return;
        }
        else if (right_child>=heap.size()){
            larger_child=left_child;
        }
        else{
            larger_child = heap[left_child]>heap[right_child]?left_child:right_child;
        }

        if(heap[index]<heap[larger_child]){
            swap(heap[index],heap[larger_child]);
            reheapificate_downward(larger_child);
        }
        else return;
    }
public:
    MaxHeap(){
        heap.push_back(NULL);
    }

    void push(T data){
        heap.push_back(data);
        reheapificate_upward(heap.size()-1);
    }

    T pop(){
        if(heap.size()==1){
            return NULL;
        }
        T pop_data = heap[1];
        heap[1] = heap[heap.size()-1];
        heap.pop_back();
        reheapificate_downward(1);

        return pop_data;
    }

    void print_heap(){
        for(int i=1;i<heap.size();i++){
            cout<<heap[i]<<" ";
        }
        cout<<endl;
    }

    int size(){
        return heap.size()-1;
    }
};

int main(){
    MaxHeap<int> mh = MaxHeap<int>();
    int data[6] = {7,3,9,5,10,4};

    for(int i=0;i<6;i++){
        cout<<"In heap "<<data[i]<<" add: ";
        mh.push(data[i]);
        mh.print_heap();
    }
    cout<<endl;

    while(mh.size()>0){
        cout<<"delete maximum value in heap: "<<mh.pop()<<endl;
        cout<<"current heap status: ";
        mh.print_heap();
    }
}