//최소 스패닝 트리(Kruskal's algorithm)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Graph {
private:
    vector<pair<int, pair<int, int>>> edges; // {weight, {u, v}}
    int vertices;

    int find(vector<int>& parent, int i) {
        if (parent[i] != i) {
            parent[i] = find(parent, parent[i]);
        }
        return parent[i];
    }

    void unionSet(vector<int>& parent, vector<int>& rank, int x, int y) {
        int xroot = find(parent, x);
        int yroot = find(parent, y);

        if (rank[xroot] < rank[yroot]) {
            parent[xroot] = yroot;
        } else if (rank[xroot] > rank[yroot]) {
            parent[yroot] = xroot;
        } else {
            parent[yroot] = xroot;
            rank[xroot]++;
        }
    }

public:
    Graph(int v) : vertices(v) {}

    void addEdge(int u, int v, int weight) {
        edges.push_back({weight, {u, v}});
    }

    void kruskalMST() {
        sort(edges.begin(), edges.end());

        vector<int> parent(vertices);
        vector<int> rank(vertices, 0);

        for (int i = 0; i < vertices; ++i) {
            parent[i] = i;
        }

        vector<pair<int, pair<int, int>>> mst;
        int mstWeight = 0;

        for (auto& edge : edges) {
            int weight = edge.first;
            int u = edge.second.first;
            int v = edge.second.second;

            int setU = find(parent, u);
            int setV = find(parent, v);

            if (setU != setV) {
                mst.push_back(edge);
                mstWeight += weight;
                unionSet(parent, rank, setU, setV);
            }
        }

        cout << "Minimum Spanning Tree Weight: " << mstWeight << "\n";
        cout << "Edges in MST:\n";
        for (auto& edge : mst) {
            cout << edge.second.first << " - " << edge.second.second << " (Weight: " << edge.first << ")\n";
        }
    }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 6);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);

    g.kruskalMST();
    return 0;
}