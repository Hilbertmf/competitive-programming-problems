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
    
    int n, m, start, target;
    cin >> n >> m >> start >> target;
    start--;
    target--;
    vector<vector<pair<int, int>>> graph(n);
    priority_queue<vector<int>> heap;
    map<pair<int, int>, int> edges;

    for(int i = 0; i < m; ++i) {
        int a, b, f;
        cin >> a >> b >> f;
        a--; b--;
        graph[a].push_back({b, f});
        edges[{a, b}] = f;
    }

    heap.push({INF, INF, start});
    vector<char> vis(n, false);
    vis[start] = true;
    int ans = -1;

    while (!heap.empty()) {
        int curr_f = heap.top()[1];
        int d = heap.top()[0];
        int v = heap.top()[2];
        heap.pop();
        
        if (v == target) {
            ans = curr_f;
            break;
        }

        for(auto &[u, f] : graph[v]) {
            if (vis[u]) continue;
            vis[u] = true;
            heap.push({min(f, curr_f), f, u});
        }
    }

    cout << ans << "\n";    


    return 0;
}
