#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

#define INF 1e9
typedef pair<int, int> pii;

int primsMST(int v, vector<vector<pii>> &adj) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<bool> visited(v, false);
    pq.push(make_pair(0, 0));
    int total = 0;

    while (!pq.empty()) {
        pii top = pq.top(); pq.pop();
        int w = top.first;
        int u = top.second;

        if (visited[u]) continue;
        visited[u] = true;
        total += w;

        for (int i = 0; i < adj[u].size(); i++) {
            int neighbor = adj[u][i].first;
            int wt = adj[u][i].second;
            if (!visited[neighbor]) {
                pq.push(make_pair(wt, neighbor));
            }
        }
    }
    return total;
}

int main() {
    int v;
    cout << "Enter number of vertices: ";
    cin >> v;

    vector<vector<pii>> adj(v);

    cout << "Enter edges in format (u v w). Enter -1 -1 -1 to stop:\n";
    while (true) {
        int u, vv, w;
        cin >> u >> vv >> w;
        if (u == -1 && vv == -1 && w == -1)
            break;
        if (u < 0 || vv < 0 || u >= v || vv >= v) {
            cout << "Invalid vertex! Must be in range 0 to " << v - 1 << ". Try again.\n";
            continue;
        }
        adj[u].push_back(make_pair(vv, w));
        adj[vv].push_back(make_pair(u, w)); // undirected
    }

    int totalWeight = primsMST(v, adj);
    cout << "Total weight of MST: " << totalWeight << endl;

    return 0;
}
