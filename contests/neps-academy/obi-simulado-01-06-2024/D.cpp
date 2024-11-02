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
    
    int n, m;
    cin >> n >> m;
    vector<set<int>> graph(n);

    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        v--; u--;
        graph[u].insert(v);
    }

    bool ok = false;
    for(int i = 0; i < n && !ok; ++i) {
        if (graph[i].size() >= n - 1)
            ok = true;
    }

    if(ok) {
        cout << "S\n";
    }
    else {
        cout << "N\n";
    }

    return 0;
}
