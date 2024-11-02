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
    vector<pair<int, int>> a(m);
    set<pair<int, int>> unsafe;
    for(int i = 0; i < m; ++i) {
        cin >> a[i].first >> a[i].second;
        auto [x, y] = a[i];

        unsafe.insert({x, y});
        if (x + 2 <= n && y + 1 <= n)
            unsafe.insert({x + 2, y + 1});
        if (x + 2 <= n && y - 1 >= 1)
            unsafe.insert({x + 2, y - 1});
        if (x - 2 >= 1 && y + 1 <= n)
            unsafe.insert({x - 2, y + 1});
        if (x - 2 >= 1 && y - 1 >= 1)
            unsafe.insert({x - 2, y - 1});

        if (x + 1 <= n && y + 2 <= n)
            unsafe.insert({x + 1, y + 2});
        if (x - 1 >= 1 && y + 2 <= n)
            unsafe.insert({x - 1, y + 2});
        if (x + 1 <= n && y - 2 >= 1)
            unsafe.insert({x + 1, y - 2});
        if (x - 1 >= 1 && y - 2 >= 1)
            unsafe.insert({x - 1, y - 2});
    }

    int ans = (n * n) - unsafe.size();
    cout << ans << "\n";

    return 0;
}
