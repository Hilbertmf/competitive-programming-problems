class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                int k = nums[i] | nums[j];
                if(k % 2 == 0)
                    return true;
            }
        }

        return false;
    }
};