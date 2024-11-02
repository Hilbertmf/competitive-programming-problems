// WA
#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long

int getDepths(int cur, int par, vector<vector<int>>& tree,
vector<int>& depths, vector<int>& dist) {
    if (cur != 0 && tree[cur].size() == 1) // leaf
        return 0;
    
    int best = -1;
    int second = -1;
    for(auto &adj : tree[cur]) {
        if (adj == par) continue;
        int child = getDepths(adj, cur, tree, depths, dist);
        if (child > best) {
            second = best;
            best = child;
        }
        else if (child > second)
            second = child;
    }
    depths[cur] = best + 1;
    dist[cur] = best + second;
    if (second > -1) dist[cur] += second;
    return depths[cur];
}

void getDepth(int cur, vector<int>& par, vector<vector<int>>& tree,
vector<int>& depths, int d) {
    depths[cur] = d;
    for(auto &adj : tree[cur]) {
        if (adj == par[cur]) continue;
        par[adj] = cur;
        getDepth(adj, par, tree, depths, d + 1);
    }
}

int32_t main() {
    int n, u, v;
    cin >> n;
    vector<vector<int>> tree(n);
    for(int i = 0; i < n - 1; ++i) {
        cin >> u >> v;
        --u; --v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    vector<int> depths(n);
    vector<int> dist(n);
    vector<int> par(n);
    getDepths(0, par, tree, depths, dist);

    // find lca and get dist
    if ()
    
    int diameter = 0;
    for(int i = 0; i < n; ++i) {
        diameter = max(diameter, dist[i]);
    }
    cout << diameter << "\n";

    return 0;
}