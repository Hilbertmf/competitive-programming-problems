// O(n²) needs improvement 
// TLE
#include <bits/stdc++.h> 
using namespace std; 
#define DEBUG(x) cout << #x << " >>>> " << x << endl 
#define MID(l, r) (l + (r - l) / 2) 
#define CEILDIVISION(x, y) ((x + y - 1) / y) 
#define INF (int)1e9 
#define LONGINF (long long)1e18 
#define MEM(arr, val) memset(arr, (val), sizeof(arr)) 
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
#define int long long 
const int MOD = 1e9 + 7; // 10^9 + 7 

int32_t main() { 
    FASTIO;
    int r, c, a, b;
    cin >> r >> c >> a >> b;

    int dp[r][c];

    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j) {
            dp[i][j] = -1;
        }
    }

    dp[1][1] = 2;
    for(int i = 0; i < r ; ++i) {
        dp[i][0] = 1;
    }
    for(int i = 0; i < c; ++i) {
        dp[0][i] = 1;
    }

    for(int i = 1; i < r; ++i) {
        for(int j = 1; j < c; ++j) {
            // if(dp[i][j] != 0)
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }

    for(int i = r - 1; i >= r - a; --i) {
        for(int j = 0; j < b; ++j) {
            dp[i][j] = 0;
        }
    }

    for(int i = r - 1 - a; i < r; ++i) {
        for(int j = c - 1 - b; j < c; ++j) {
            if(dp[i][j] != 0)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }

    cout << dp[r-1][c-1] << "\n";

    // print
    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }


    return 0;
}