// https://atcoder.jp/contests/abc378/tasks/abc378_b
// AC
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
    int n, Q;
    cin >> n;
    vector<int> q(n), r(n);
    for(int i = 0; i < n; ++i) {
        cin >> q[i] >> r[i];
    }

    cin >> Q;

    while (Q--) {
        int tt, d;
        cin >> tt >> d;

        int mod = d % q[tt - 1];
        if (mod == r[tt - 1]) {
            cout << d << "\n";
        }
        else {
            int ans;
            if(mod < r[tt-1]) {
                ans = d + (r[tt-1] - mod);
            }
            else {
                ans = d + (q[tt-1] - mod) + r[tt-1];
            }
            cout << ans << "\n";
        }
    }

    return 0;
}
