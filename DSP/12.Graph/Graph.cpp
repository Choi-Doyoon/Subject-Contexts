#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

template<typename T>
class Graph{
private:
    int size;
    vector<T> data;
    vector<vector<bool>> adj_matrix;

public:
    Graph(){
        size = 0;
        data = vector<T>();
        adj_matrix = vector<vector<bool>>();
    }

    void add_node(const T& value){
        size++;
        data.push_back(value);
        adj_matrix.push_back(vector<bool>(size-1,false));
        for(int i=0;i<adj_matrix.size();i++){
            adj_matrix[i].push_back(false);
        }
    }

    void remove_node(const T& value){
        int index = -1;
        for(int i=0;i<size;i++){
            if(data[i] == value){
                index = i;
                break;
            }
        }
        if(index == -1) return;

        data.erase(data.begin() + index);
        for(int i=0;i<size;i++){
            adj_matrix[i].erase(adj_matrix[i].begin() + index);
        }
        adj_matrix.erase(adj_matrix.begin() + index);
        size--;
    }

    void add_edge(size_t source, size_t target){
        if(source<size && target<size){
            adj_matrix[source][target]=true;
        }
    }

    void remove_edge(size_t source, size_t target){
        if(source<size && target<size){
            adj_matrix[source][target]=false;
        }
    }

    bool is_edge(size_t source, size_t target){
        return adj_matrix[source][target];
    }

    int get_size(){
        return size;
    }

    T get_value(size_t index){
        return data[index];
    }

    int in_degree(size_t index){
        int id=0;
        for(int i=0;i<size;i++){
            id += adj_matrix[i][index];
        }
        return id;
    }

    int out_degree(size_t index){
        int od=0;
        for(int i=0;i<size;i++){
            od += adj_matrix[index][i];
        }
        return od;
    }

    int degree(size_t Index){
        return in_degree(Index) + out_degree(Index);
    }

    void print_adj(){
        cout<<"\n\t";
        for(int i=0;i<size;i++){
            cout<<data[i]<<"\t";
        }
        cout<<endl;
        for(int i=0;i<size;i++){
            cout<<data[i]<<"\t";
            for(int j=0;j<size;j++){
                cout<<adj_matrix[i][j]<<"\t";
            }
            cout<<endl;
        }
        cout<<endl;
    }

    void DFS(Graph<T> g, int start){
        vector<bool> is_visited = vector<bool>(g.get_size(),false);
        stack<int> _stack=stack<int>();

        cout<<"DFS visit order: "<<endl;
        _stack.push(start);
        while(!_stack.empty()){
            int index = _stack.top();
            _stack.pop();
            cout<<g.get_value(index)<<" -> ";
            is_visited[index]=true;

            for(int i = g.get_size() - 1; i >= 0; i--){
                if(g.is_edge(index,i) && !is_visited[i]){
                    _stack.push(i);
                }
            }
        }
    }

    void BFS(Graph<T> g, int start){
        vector<bool> is_visited = vector<bool>(g.get_size(),false);
        queue<int> _queue = queue<int>();

        cout<<"BFS visit order: "<<endl;
        cout<<g.get_value(start)<<" -> ";
        is_visited[start]=true;
        _queue.push(start);
        while(!_queue.empty()){
            int index = _queue.front();
            _queue.pop();

            for(int i=0;i<g.get_size();i++){
                if(g.is_edge(index,i) && !is_visited[i]){
                    cout<<g.get_value(i)<<" -> ";
                    is_visited[i]=true;
                    _queue.push(i);
                }
            }
        }
    }
};

int main(){
    Graph<string> g = Graph<string>();

    g.add_node("minsoo");
    g.add_node("jihyang");
    g.add_node("moonjeong");
    g.add_node("jihyeon");
    g.add_node("ilsang");
    g.add_node("sunmin");
    g.add_node("sieun");

    g.add_edge(0,1);
    g.add_edge(0,2);
    g.add_edge(0,4);
    g.add_edge(1,3);
    g.add_edge(3,0);
    g.add_edge(3,5);
    g.add_edge(3,6);
    g.add_edge(6,1);    

    g.print_adj();
    g.DFS(g,0);
    cout<<endl;
    g.BFS(g,0);
    cout<<endl;
}