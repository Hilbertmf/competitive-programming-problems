// acc TALVEZ SE ESSA MERDA DESSE URI ME DEIXASSE SUBMETER
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

int bfs(int src, vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> dists(n, INF);
    queue<pair<int, int>> qu;
    vector<char> vis(n, 0);
    qu.push({src, 0});
    vis[src] = 1;
    dists[src] = 0;
    int dist = 0;

    while (!qu.empty()) {
        int node = qu.front().first;
        int d = qu.front().second;
        dists[node] = d;
        qu.pop();

        for(auto &adj : graph[node]) {
            if (vis[adj]) continue;
            vis[adj] = 1;
            qu.push({adj, d + 1});
        }
    }

    return *max_element(dists.begin(), dists.end());
}

int32_t main() {
    FASTIO;

    int n, m, d;
    cin >> n >> m >> d;
    int max_dist = 0;
    vector<vector<int>> graph(n);
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(int i = 0; i < n; ++i) {
        int dist = bfs(i, graph);
        max_dist = max(max_dist, dist);
    }

    int total = d + d + 1;
    int ans = total - max_dist;

    if (ans < 0) ans = 0;

    cout << ans << " " << ans << "\n";

    return 0;
}
