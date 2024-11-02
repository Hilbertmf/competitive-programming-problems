#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_map<long long, long long>> dp(n);
        long long ans = 0;
        for(int i = n - 1; i >= 0; i--) {
            for(int j = i + 1; j < n; j++) {
                long long diff = (long long)nums[j] - nums[i];
                long long curr = dp[j][diff] + 1;
                dp[i][diff] += curr;
                ans += curr;
            }
        }
        ans -= (n*(n-1))/2;
        return ans;
    }
};