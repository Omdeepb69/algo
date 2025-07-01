#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, wt;
};

bool edgeCmp(Edge a, Edge b) {
    return a.wt < b.wt;
}

int find(int parent[], int i) {
    if (parent[i] != i) parent[i] = find(parent, parent[i]);
    return parent[i];
}

void kruskalMST(int V, vector<Edge> &edges) {
    sort(edges.begin(), edges.end(), edgeCmp);
    int parent[1000]; // supports up to 1000 vertices
    for (int i = 0; i < V; i++) parent[i] = i;

    int totalWeight = 0;
    cout << "\nEdges in MST:\n";
    for (auto &e : edges) {
        int x = find(parent, e.u);
        int y = find(parent, e.v);
        if (x != y) {
            cout << e.u << " - " << e.v << " (weight " << e.wt << ")\n";
            totalWeight += e.wt;
            parent[y] = x;
        }
    }
    cout << "Total weight of MST: " << totalWeight << endl;
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<Edge> edges(E);
    cout << "Enter " << E << " edges in format: u v weight (0-based indexing)\n";
    for (int i = 0; i < E; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].wt;
    }

    kruskalMST(V, edges);
    return 0;
}
