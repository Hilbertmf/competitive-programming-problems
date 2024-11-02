#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

int ans = 0;

void solve(int i, vector<vector<int>>& a, int& curr,
vector<char>& vis) {
    if (i >= 6) {
        ans = max(ans, curr);
        return;
    }

    for(int k = 0; k < 6; ++k) {
        if (vis[k]) continue;
        
        curr += a[i][k];
        vis[k] = true;
        solve(i + 1, a, curr, vis);
        vis[k] = false;
        curr -= a[i][k];
    }    
}

int32_t main() {
    FASTIO;

    vector<vector<int>> a(6, vector<int>(6));
    
    for(int i = 0; i < 6; ++i) {        
        for(int j = 0; j < 6; ++j) {
            cin >> a[i][j];
        }
    }

    int curr = 0;

    vector<char> vis(6);
    solve(0, a, curr, vis);

    cout << ans << "\n";

    return 0;
}

