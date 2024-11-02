#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

int32_t main() {
    FASTIO;
    int n, m, a, b;
    cin >> n >> m;

    vector<vector<int>> graph(n);
    for(int i = 0; i < m; ++i) {
        cin >> a >> b;
        --a; --b;
        graph[a].push_back(b);
    }

    int target = 0, ans = -1;

    queue<pair<int, int>> qu;
    qu.push({0, 0});
    vector<char> vis(n);

    while (!qu.empty()) {
        auto [v, d] = qu.front();
        qu.pop();

        if (vis[v] && v != 0) continue;
        else if (vis[v] && v == 0) {
            ans = d; break;
        }
        vis[v] = true;

        for(auto &adj : graph[v]) {
            qu.push({adj, d + 1});
        }
    }
    
    cout << ans << "\n";

    return 0;
}
