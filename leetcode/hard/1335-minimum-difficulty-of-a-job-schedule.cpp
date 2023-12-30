class Solution {
public:
    const int INF = 1e9;

    int getMinDiff(int d, int n, vector<int>& diffs, vector<vector<int>>& dp,
    vector<vector<int>>& max_in_range) {

        if(dp[d][n] != -INF)
            return dp[d][n];
        if(d > n)
            return dp[d][n] = -1;
        
        if(d == 1) {
            return dp[d][n] = max_in_range[0][n - 1];
        }
        
        int ans = INF;
        int end = n;

        for(int i = d - 1; i < end; ++i) {
            
            int left = getMinDiff(d - 1, i, diffs, dp, max_in_range);
            if(left == -1)
                continue;

            ans = min(ans,
                      left + max_in_range[i][end - 1]);
        }

        if(ans == INF)
            ans = -1;
        return dp[d][n] = ans;
    }
    
    int minDifficulty(vector<int>& jobDifficulty, int d) {

        int n = jobDifficulty.size();
        vector<vector<int>> dp(d + 1, vector<int>(n + 1, -INF));
        vector<vector<int>> max_in_range(n + 1, vector<int>(n + 1));

        for(int i = 0; i < n; ++i) {
            max_in_range[i][i] = jobDifficulty[i];
            for(int j = i + 1; j < n; ++j) {
                max_in_range[i][j] = *max_element(jobDifficulty.begin() + i, jobDifficulty.begin() + j + 1);
            }
        }

        return getMinDiff(d, n, jobDifficulty, dp, max_in_range);
    }
};