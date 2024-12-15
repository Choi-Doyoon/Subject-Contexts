//그래프 탐색 경로 존재 여부(DFS)
#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    vector<vector<int>> adj;
    vector<bool> visited;

    bool dfs(int current, int target) {
        if (current == target) return true;
        visited[current] = true;

        for (int neighbor : adj[current]) {
            if (!visited[neighbor] && dfs(neighbor, target)) {
                return true;
            }
        }

        return false;
    }

public:
    Graph(int vertices) : adj(vertices), visited(vertices, false) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // 무방향 그래프
    }

    bool isPathExist(int start, int end) {
        fill(visited.begin(), visited.end(), false);
        return dfs(start, end);
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(3, 4);

    int start = 0, end = 4;
    if (g.isPathExist(start, end)) {
        cout << "Path exists from " << start << " to " << end << "\n";
    } else {
        cout << "No path exists from " << start << " to " << end << "\n";
    }

    return 0;
}