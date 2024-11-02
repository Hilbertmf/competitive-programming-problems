// cses dice combinations
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl

int main() {

    int n, X;
    cin >> n >> X;
    vector<int> coins(n+1);
    for(int i = 1; i <= n; ++i) cin >> coins[i];

    int dp[X + 1][n + 1];
    for(int x = 0; x <= X; ++x) {
        for(int i = 0; i <= n; ++i) {
            dp[x][i] = 0;
            // if (coins[i])
            // dp[coins[i]][i] = 1;
        }
        // fill(dp[x], dp[x] + n + 1, 0);
    }


    for(int x = 0; x <= X; ++x) {
        for(int i = 1; i <= n; ++i) {
            int inc = 0;
            int exc = dp[x][i - 1];
            if (coins[i] <= x) {
                inc = dp[x - coins[i]][i - 1];
            }
            
            dp[x][i] = inc + exc;
            // DEBUG(dp[x][i]);
        }
    }    

    cout << dp[X][n] << "\n";

    return 0;
}