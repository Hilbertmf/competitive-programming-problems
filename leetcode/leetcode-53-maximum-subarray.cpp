#include <bits/stdc++.h> 
using namespace std;

// Divide and conquer solutions:
// Time: O(n)
// Space: O(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0], curr_max = nums[0];
        for(int i = 1; i < nums.size(); ++i) {
            curr_max = max(nums[i], nums[i] + curr_max);
            ans = max(ans, curr_max);
        }
        return ans;
    }
};


// Divide and conquer w/ recursion
// Time: O(n)
// Space: O(n)

class Solution {
public:
    int greaterSubArray(vector<int>& nums, int idx, int& ans) {
        if(idx == 0) return nums[0];
        int best = max(nums[idx],
        greaterSubArray(nums, idx - 1, ans) + nums[idx]);

        ans = max(ans, best);    
        return best;
    }

    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        greaterSubArray(nums, nums.size() - 1, ans);
        return ans;
    }
};

// Greedy solution w/ prefix sum
// Time: O(n)
// Space: O(n)

class Solution {
public:

    int maxSubArray(vector<int>& nums) {
        vector<int> prefix(nums.size());
        prefix[0] = nums[0];
        int ans = nums[0];
        for(int i = 1; i < prefix.size(); ++i) {
            prefix[i] = nums[i] + prefix[i-1];
            ans = max({ans, nums[i], prefix[i]});
        }

        int minN = prefix[0];

        for(int i = 1; i < prefix.size(); ++i) {
            ans = max(ans, prefix[i] - minN);
            minN = min(minN, prefix[i]);
        }

        return ans;
    }
};