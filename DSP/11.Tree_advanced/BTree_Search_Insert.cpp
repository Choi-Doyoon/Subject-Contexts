#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

template<typename T>
class BTreeNode{
public:
    BTreeNode* parent;
    vector<BTreeNode*> children;
    vector<T> dataset;

    BTreeNode(BTreeNode* init_parent=nullptr, vector<BTreeNode*> init_children=vector<BTreeNode*>(), vector<T> init_dataset=vector<T>()){
        parent=init_parent;
        children=init_children;
        dataset=init_dataset;
    };

    bool is_leaf(){
        return children.size()==0;
    }

    void loose_insert(T data){
        dataset.push_back(data);
        sort(dataset.begin(), dataset.end());
    }

    BTreeNode* split_child(int index){
        int mid=children[index]->dataset.size()/2;
        loose_insert(children[index]->dataset[mid]);

        BTreeNode* left=new BTreeNode(children[index]->parent);
        BTreeNode* right=new BTreeNode(children[index]->parent);

        for(int i=0;i<children[index]->dataset.size();i++){
            if(i<mid){
                left->dataset.push_back(children[index]->dataset[i]);
            }
            else if(i>mid){
                right->dataset.push_back(children[index]->dataset[i]);
            }
        }
        if(!children[index]->is_leaf()){
            for(int i=0;i<children[index]->children.size();i++){
                if(i<=mid){
                    left->children.push_back(children[index]->children[i]);
                    children[index]->children[i]->parent=left;
                }
                else if(i>mid){
                    right->children.push_back(children[index]->children[i]);
                    children[index]->children[i]->parent=right;
                }
            }
        }

        BTreeNode* temp = children[index];
        children[index]=right;
        children.insert(children.begin()+index,left);
        delete temp;

        return right->parent;
    }

    void print_data(){
        cout<<"[ ";
        for(int i=0;i<dataset.size();i++){
            cout<<dataset[i]<<" ";
        }
        cout<<"]";
    }
};

template<typename T>
class BTree{
private:
    const int M;
    BTreeNode<T>* root_ptr;

    BTreeNode<T>* search_recursion(BTreeNode<T>* node, T data){
        if(node->is_leaf()){
            auto it=find(node->dataset.begin(),node->dataset.end(),data);
            if(it != node->dataset.end()){
                return node;
            }
            else{
                return nullptr;
            }
        }

        if(data<node->dataset[0]){
            return search_recursion(node->children[0],data);
        }
        else if(data==node->dataset[0]){
            return node;
        }
        for(int i=1;i<node->dataset.size();i++){
            if(node->dataset[i-1]<data&&data<node->dataset[i]){
                return search_recursion(node->children[i],data);
            }
            else if(data==node->dataset[i]){
                return node;
            }
        }
        if(data>node->dataset.back()){
            return search_recursion(node->children.back(),data);
        }
    }

    BTreeNode<T>* find_insert_point(BTreeNode<T>* node, T data){
        if(node->is_leaf()){
            return node;
        }

        if(data<=node->dataset[0]){
            return find_insert_point(node->children[0],data);
        }
        for(int i=1;i<node->dataset.size();i++){
            if(node->dataset[i-1]<data&&data<node->dataset[i]){
                return find_insert_point(node->children[i],data);
            }
        }
        if(data>node->dataset.back()){
            return find_insert_point(node->children.back(),data);
        }
    }

    void fix_excess(BTreeNode<T>* node){
        if(node->dataset.size()<M){
            return;
        }

        if(node==root_ptr){
            BTreeNode<T>* new_root=new BTreeNode<T>(nullptr,vector<BTreeNode<T>*>(1,node));
            node->parent=new_root;
            root_ptr=new_root->split_child(0);
        }
        else{
            auto it = find(node->parent->children.begin(),node->parent->children.end(),node);
            int split_index=distance(node->parent->children.begin(),it);
            fix_excess(node->parent->split_child(split_index));
        }
    }
public:
    BTree(int maximum=3, BTreeNode<T>* init_root=nullptr):M(maximum){
        root_ptr=init_root;
    }

    bool count(T data){
        return search_recursion(root_ptr,data)!=nullptr;
    }

    void insert(T data){
        if(root_ptr==nullptr){
            root_ptr=new BTreeNode<T>();
            root_ptr->loose_insert(data);
        }
        else{
            BTreeNode<T>* insert_point=find_insert_point(root_ptr,data);
            insert_point->loose_insert(data);
            fix_excess(insert_point);
        }
    }

    void print_tree(){
        queue<BTreeNode<T>*> node_queue=queue<BTreeNode<T>*>();
        int current_level=0;
        int next_level=0;
        int count=0;

        node_queue.push(root_ptr);
        root_ptr->print_data();
        cout<<endl;

        while(!node_queue.empty()){
            BTreeNode<T>* node=node_queue.front();
            node_queue.pop();

            if(!node->is_leaf()){
                cout<<"[";
                for(int i=0;i<node->children.size();i++){
                    node_queue.push(node->children[i]);
                    node->children[i]->print_data();
                    next_level++;
                }
                cout<<"] ";
            }    

            count++;
            if(count>=current_level){
                cout<<endl;
                current_level=next_level;
                next_level=0;
                count=0;
            }    
        }
    }
};

int main(){
    BTree<int> bt = BTree<int>(3);
    int data[7] = {10,15,20,30,40,5,1};

    for(int i=0;i<7;i++){
        cout<<"In BTree "<<data[i]<<" add: "<<endl;
        bt.insert(data[i]);
        bt.print_tree();
    }

    cout<<"In BTree 20 is "<<bt.count(20)<<endl;
    cout<<"In BTree -19 is "<<bt.count(-10)<<endl;
}