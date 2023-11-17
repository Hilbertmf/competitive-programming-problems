class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int sum = 0;
        int l = 0, r = nums.size() - 1;
        sort(nums.begin(), nums.end());

        while(l <= r) {
            sum = max(sum, nums[l] + nums[r]);
            l++;
            r--;
        }

        return sum;
    }
};
