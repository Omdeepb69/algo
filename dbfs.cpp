#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void DFS(int v, vector<vector<int>> &adj, vector<bool> &visited) {
    visited[v] = true;
    cout << v << " ";
    for (int u : adj[v])
        if (!visited[u]) DFS(u, adj, visited);
}

void BFS(int start, vector<vector<int>> &adj, int V) {
    vector<bool> visited(V, false);
    queue<int> q;
    visited[start] = true;
    q.push(start);
    while (!q.empty()) {
        int v = q.front(); q.pop();
        cout << v << " ";
        for (int u : adj[v]) {
            if (!visited[u]) {
                visited[u] = true;
                q.push(u);
            }
        }
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> adj(V);
    cout << "Enter " << E << " edges (u v) (0-based indexing):\n";
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected graph
    }

    int start;
    cout << "Enter starting node for DFS & BFS: ";
    cin >> start;

    cout << "\nDFS Traversal: ";
    vector<bool> visited(V, false);
    DFS(start, adj, visited);

    cout << "\nBFS Traversal: ";
    BFS(start, adj, V);

    cout << endl;
    return 0;
}
