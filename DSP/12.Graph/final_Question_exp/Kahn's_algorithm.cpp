//위상 정렬 구현(Kahn's algorithm)
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
private:
    vector<vector<int>> adj;
    vector<int> indegree;

public:
    Graph(int vertices) : adj(vertices), indegree(vertices, 0) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        indegree[v]++;
    }

    void topologicalSort() {
        queue<int> q;

        // 진입 차수가 0인 노드를 큐에 추가
        for (int i = 0; i < indegree.size(); ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topoOrder;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topoOrder.push_back(node);

            for (int neighbor : adj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        if (topoOrder.size() != adj.size()) {
            cout << "Cycle detected! Topological sort not possible.\n";
        } else {
            cout << "Topological Order: ";
            for (int v : topoOrder) {
                cout << v << " ";
            }
            cout << "\n";
        }
    }
};

int main() {
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    g.topologicalSort();
    return 0;
}
