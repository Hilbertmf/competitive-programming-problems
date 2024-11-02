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

    int n, c;
    cin >> n >> c;
    vector<int> t(n);
    for(int i = 0; i < n; ++i) {
        cin >> t[i];
    }

    int ans = 1;
    int last = t[0];
    for(int i = 1; i < n; ++i) {
        if (t[i] - last >= c) {
            last = t[i];
            ans++;
        }
    }

    cout << ans << "\n";

    return 0;
}
