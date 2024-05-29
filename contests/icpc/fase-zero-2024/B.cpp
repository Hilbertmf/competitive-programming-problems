// acc
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// #define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

int main() {
    FASTIO;
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, int>>> graph(n);
    for(int i = 0; i < m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        u--;
        v--;
        graph[u].push_back({v, c});
        graph[v].push_back({u, c});
    }

    int ans = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;

    heap.push({0, 0});
    vector<char> vis(n, 0);
    int visited_cities = 0;
    while (!heap.empty() && visited_cities < k) {
        int time = heap.top().first;
        int curr = heap.top().second;
        heap.pop();

        ans = max(ans, time);

        if (vis[curr]) continue;
        vis[curr] = 1;
        visited_cities++;

        for(auto &[adj, c] : graph[curr]) {
            if (vis[adj]) continue;
            heap.push({c, adj});
        }
    }
    

    cout << ans << "\n";

    return 0;
}
