#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
void towerOfHanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        cout << "Move disk 1 from " << from << " to " << to << endl;
        return;
    }
    towerOfHanoi(n-1, from, aux, to);
    cout << "Move disk " << n << " from " << from << " to " << to << endl;
    towerOfHanoi(n-1, aux, to, from);
}

// 2. Binary Search (Recursive)
int binarySearch(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x) return mid;
        if (arr[mid] > x) return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

// 3. Sorting and Linear Search
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > key) arr[j+1] = arr[j--];
        arr[j+1] = key;
    }
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx]) min_idx = j;
        swap(arr[min_idx], arr[i]);
    }
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
}

int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++)
        if (arr[i] == x) return i;
    return -1;
}

// 4. Merge Sort
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int* L = new int[n1];
    int* R = new int[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int i = 0; i < n2; i++) R[i] = arr[m + 1 + i];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// 5. Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high], i = low - 1;
    for (int j = low; j <= high - 1; j++)
        if (arr[j] < pivot) swap(arr[++i], arr[j]);
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// 6. Fractional Knapsack (Greedy)
struct Item {
    int value, weight;
};

bool cmp(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, Item arr[], int n) {
    sort(arr, arr + n, cmp);
    double result = 0.0;
    for (int i = 0; i < n && W > 0; i++) {
        if (arr[i].weight <= W) {
            W -= arr[i].weight;
            result += arr[i].value;
        } else {
            result += arr[i].value * ((double)W / arr[i].weight);
            break;
        }   
    }
    return result;
}

// 7. Job Sequencing
struct Job {
    char id;
    int deadline, profit;
};

bool jobCompare(Job a, Job b) {
    return a.profit > b.profit;
}

void jobScheduling(Job arr[], int n) {
    sort(arr, arr + n, jobCompare);
    int result[n] = {0};
    bool slot[n] = {false};
    for (int i = 0; i < n; i++) {
        for (int j = min(n, arr[i].deadline) - 1; j >= 0; j--) {
            if (!slot[j]) {
                result[j] = i;
                slot[j] = true;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++)
        if (slot[i]) cout << arr[result[i]].id << " ";
}

// 8. Prim’s and Kruskal’s
// Prim’s and Kruskal’s MST implementations are long, want me to include optimized versions?

// 9. DFS and BFS
// 10. Rabin-Karp and KMP
// 11. Dijkstra
// These will be added in the next block due to size limits.



#define INF 1e9

typedef pair<int, int> pii;

int primMST(int V, vector<vector<pii>> &adj) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<bool> visited(V, false);
    pq.push({0, 0});
    int total = 0;
    while (!pq.empty()) {
        auto [w, u] = pq.top(); pq.pop();
        if (visited[u]) continue;
        visited[u] = true;
        total += w;
        for (auto &[v, wt] : adj[u])
            if (!visited[v]) pq.push({wt, v});
    }
    return total;
}

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
    int parent[V];
    for (int i = 0; i < V; i++) parent[i] = i;
    for (auto &e : edges) {
        int x = find(parent, e.u);
        int y = find(parent, e.v);
        if (x != y) {
            cout << e.u << " - " << e.v << "\n";
            parent[y] = x;
        }
    }
}

// 9. DFS and BFS
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

// 10. Rabin-Karp and KMP
void RabinKarp(string txt, string pat, int q) {
    int d = 256;
    int n = txt.length(), m = pat.length();
    int p = 0, t = 0, h = 1;
    for (int i = 0; i < m - 1; i++) h = (h * d) % q;
    for (int i = 0; i < m; i++) {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }
    for (int i = 0; i <= n - m; i++) {
        if (p == t) {
            bool match = true;
            for (int j = 0; j < m; j++)
                if (txt[i + j] != pat[j]) { match = false; break; }
            if (match) cout << "Pattern at index " << i << endl;
        }
        if (i < n - m) {
            t = (d * (t - txt[i] * h) + txt[i + m]) % q;
            if (t < 0) t += q;
        }
    }
}

void computeLPS(string pat, vector<int> &lps) {
    int len = 0, i = 1;
    lps[0] = 0;
    while (i < pat.size()) {
        if (pat[i] == pat[len]) lps[i++] = ++len;
        else if (len) len = lps[len - 1];
        else lps[i++] = 0;
    }
}

void KMPSearch(string txt, string pat) {
    int m = pat.size(), n = txt.size();
    vector<int> lps(m);
    computeLPS(pat, lps);
    int i = 0, j = 0;
    while (i < n) {
        if (pat[j] == txt[i]) i++, j++;
        if (j == m) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];
        } else if (i < n && pat[j] != txt[i]) {
            if (j) j = lps[j - 1];
            else i++;
        }
    }
}

// 11. Dijkstra
void dijkstra(int V, vector<vector<pii>> &adj, int src) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> dist(V, INF);
    dist[src] = 0;
    pq.push({0, src});
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        for (auto &[v, w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    for (int i = 0; i < V; i++) cout << i << ": " << dist[i] << endl;
}