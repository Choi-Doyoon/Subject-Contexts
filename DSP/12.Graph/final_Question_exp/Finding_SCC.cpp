//강한 연결 요소(SCC) 찾기
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Graph {
private:
    vector<vector<int>> adj;
    vector<vector<int>> reverseAdj;
    vector<bool> visited;
    stack<int> st;

    void dfs1(int node) {
        visited[node] = true;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) dfs1(neighbor);
        }
        st.push(node);
    }

    void dfs2(int node, vector<int>& component) {
        visited[node] = true;
        component.push_back(node);
        for (int neighbor : reverseAdj[node]) {
            if (!visited[neighbor]) dfs2(neighbor, component);
        }
    }

public:
    Graph(int vertices) : adj(vertices), reverseAdj(vertices), visited(vertices, false) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        reverseAdj[v].push_back(u);
    }

    void findSCCs() {
        // 1. DFS로 정렬
        for (int i = 0; i < adj.size(); ++i) {
            if (!visited[i]) dfs1(i);
        }

        // 2. DFS로 SCC 찾기
        fill(visited.begin(), visited.end(), false);
        while (!st.empty()) {
            int node = st.top();
            st.pop();

            if (!visited[node]) {
                vector<int> component;
                dfs2(node, component);

                // SCC 출력
                cout << "SCC: ";
                for (int v : component) cout << v << " ";
                cout << "\n";
            }
        }
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(1, 3);
    g.addEdge(3, 4);

    g.findSCCs();
    return 0;
}
