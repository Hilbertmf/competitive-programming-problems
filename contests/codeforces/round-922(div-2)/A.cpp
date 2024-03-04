#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
// #define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

int32_t main() {
    FASTIO;
    int t;
    cin >> t;
    
    while(t--){

        int n, m;
        cin >> n >> m;
        int row = m / 2;
        cout << row * n << "\n";
    }
    
    return 0;
}




/*

[1,15,7,9,2,5,10]
[1,15,15,15,10,10,10] = 76

[n,n,n,n,n]

[n,n,n,M,n,n,n]

for each position:
    third = sum(max(i,i-1,i-2) * 3) + dp[i - 3]
    second = sum(max(i,i-1) * 2) + dp[i - 2]
    first = arr[i] + dp[i - 1]

    dp[i] = max(first, second, third);

*/

// time: O(n² + n*k)
// space: O(n² + k)
class Solution {
public:
    int f(int i, vector<int>& arr, int k,
    vector<vector<int>>& prefix_max, vector<int>& dp) {
        if(i < 0)
            return 0;
        else if(dp[i] != -1)
            return dp[i];

        vector<int> sums(k + 1);
        for(int j = 1; j <= k && (i - j + 1) >= 0; ++j) {
            sums[j] = f(i - j, arr, k, prefix_max, dp);
            sums[j] += prefix_max[i - j + 1][i] * j;
        }

        return dp[i] = *max_element(sums.begin(), sums.end());
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {

        int n = arr.size();
        vector<vector<int>> prefix_max(n, vector<int>(n));
        vector<int> dp(n, -1);
        for(int i = 0; i < n; ++i) {
            prefix_max[i][i] = arr[i];
            int curr = arr[i];
            for(int j = i + 1; j < n; ++j) {
                prefix_max[i][j] = max(arr[j], prefix_max[i][j - 1]);
            }
        }

        f(n - 1, arr, k, prefix_max, dp);
        return *max_element(dp.begin(), dp.end());
    }
};
