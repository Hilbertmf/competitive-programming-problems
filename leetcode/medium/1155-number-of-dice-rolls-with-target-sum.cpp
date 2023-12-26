class Solution {
public:
    const int MOD = 1e9 + 7;

    // time: O(n * k * target)
    // space: O()
    // top down w/ recursion and memoization
    int countWays(int num_dice, int target, int k, vector<vector<int>>& dp) {
        if(dp[num_dice][target] != -1)
            return dp[num_dice][target];
        
        if(num_dice == 0) return dp[num_dice][target] = 0;
        if(num_dice == 1) {
            if(1 <= target && target <= k)
                return dp[num_dice][target] = 1;
            else
                return dp[num_dice][target] = 0;
        }

        int ans = 0;
        
        for(int i = 1; i <= k; ++i) {
            int new_target = new_target;
            
            if(num_dice - 1 <= new_target &&
            new_target <= (num_dice - 1) * k) {
                ans += countWays(num_dice - 1, new_target, k, dp);
                ans %= MOD;
            }
        }

        dp[num_dice][target] = ans % MOD;
        return dp[num_dice][target];
    }

    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        return countWays(n, target, k, dp) % MOD;
    }



    // bottom up
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        fill(dp[0].begin(), dp[0].end(), 0);

        for(int i = 0; i <= n; ++i) {
            for(int t = 0; t <= target; ++t) {

                if(i == 1) {
                    if(1 <= t && t <= k) {
                        dp[i][t] = 1;
                    }
                    else {
                        dp[i][t] = 0;
                    }
                }
                else if(i > 1){
                    int ans = 0;
                    for(int j = 1; j <= k; ++j) {
                        int new_target = t - j;
                        if(i - 1 <= new_target && new_target <= (i - 1) * k &&
                        new_target <= target) {
                            ans += dp[i - 1][new_target];
                            ans %= MOD;
                        }
                    }
                    dp[i][t] = ans % MOD;
                }
            }
        }

        return dp[n][target];
    }
};