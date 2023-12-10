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

    int n, s, m, l;
    cin >> n >> s >> m >> l;

    vector<int> dp(6*17 + 8*13 + 12*9 + 1, INF);
    
    for(int i = 1; i <= 12; ++i) {
        dp[i] = min({ceil(i / 6.0) * s, ceil(i / 8.0) * m, ceil(i / 12.0) * l});
    }

    for(int i = 0; i <= 17; ++i) {
        for(int j = 0; j <= 13; ++j) {
            for(int k = 0; k <= 9; ++k) {
                int num_eggs = 6 * i + 8 * j + 12 * k;
                int price = i * s + j * m + k * l;
                dp[num_eggs] = min(dp[num_eggs], price);
            }
        }
    }

    for(int i = n; i < dp.size(); ++i) {
        dp[n] = min(dp[n], dp[i]);
    }

    cout << dp[n] << "\n";
    
    
    return 0;
}
