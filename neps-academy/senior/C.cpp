#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MOD = 1e9 + 7; // 10^9 + 7

int main() {
    FASTIO;

    int n, k;
    cin >> n >> k;
    vector<int> jumps(k);
    for (int i = 0; i < k; ++i) cin >> jumps[i];

    // Remove duplicates from jumps
    set<int> jmps(jumps.begin(), jumps.end());
    jumps.assign(jmps.begin(), jmps.end()); // Convert set back to vector

    vector<int> dp(n + 1, 0); // Use n + 1 to accommodate all sums from 0 to n
    dp[0] = 1; // There's one way to reach sum 0 (using no elements)

    for (const auto &num : jumps) {
        for (int i = num; i <= n; ++i) {
            dp[i] += dp[i - num];
        }
    }

    cout << dp[n] << "\n";

    return 0;
}
