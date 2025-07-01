#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Item {
    int val, wt;
    bool operator<(Item o) const {
        return (float)val/wt > (float)o.val/o.wt;
    }
};

int main() {
    cout << "Fractional Knapsack Problem\n";
    cout << "Enter number of items and maximum weight: ";
    int n, W; cin >> n >> W;
    vector<Item> a(n);
    for (auto &i : a) cin >> i.val >> i.wt;
    sort(a.begin(), a.end());
    float ans = 0;
    for (auto &i : a) {
        int take = min(W, i.wt);
        ans += take * ((float)i.val / i.wt);
        W -= take;
        if (!W) break;
    }
    cout << fixed << setprecision(2) << ans;
}
