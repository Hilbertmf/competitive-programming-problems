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

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    int dp[n][2];
    for(int i = 0; i < n; ++i) {
        dp[i][0] = 1;
        dp[i][1] = 1;
    }

    for(int i = 1; i < n; ++i) {
        
        dp[i][0] = dp[i - 1][0];
        dp[i][1] = dp[i - 1][1];

        if (a[i] > a[i - 1]) {
            dp[i][0] = 1 + dp[i - 1][0];
            dp[i][1] = 1 + dp[i - 1][1];
        }
        else if (i > 1 && a[i] > a[i - 2]) {
            dp[i][1] = 1 + dp[i - 2][0];
        }
    }

    int ans = 1;
    for(int i = 0; i < n; ++i) {
        ans = max({ans, dp[i][0], dp[i][1]});
    }
    cout << ans << "\n";

    return 0;
}
