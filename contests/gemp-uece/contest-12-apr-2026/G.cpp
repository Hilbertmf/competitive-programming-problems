// AC
// https://codeforces.com/problemset/problem/363/B
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

int get_prefix_sum(vector<int>& p, int l, int r) {
    if (l == 0) return p[r];
    return p[r] - p[l - 1];
}

int32_t main() {
    FASTIO;
    int n, k;
    cin >> n >> k;
    vector<int> h(n), p(n);
    for(int i = 0; i < n; ++i) cin >> h[i];
    
    p = h;
    for(int i = 1; i < n; ++i) {
        p[i] += p[i - 1];
    }

    // sliding window
    int cur = 0, best = INF, ans = 0;
    for(int i = k - 1; i < n; ++i) {
        cur = get_prefix_sum(p, i - (k - 1), i);
        if (cur < best) {
            best = cur;
            ans = i - (k - 1);
        }
    }

    cout << ans + 1 << "\n";
    return 0;
}