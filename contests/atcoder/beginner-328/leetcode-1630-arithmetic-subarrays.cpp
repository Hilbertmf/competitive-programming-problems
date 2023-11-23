// O(m*nlogn)
class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> res;

        for(int i = 0; i < l.size(); ++i) {
            vector<int> tmp;
            for(int j = l[i]; j <= r[i]; ++j) {
                tmp.push_back(nums[j]);
            }
            sort(tmp.begin(), tmp.end());

            bool is_arith = true;
            for(int j = 0; j < tmp.size() - 1 && is_arith; ++j) {
                if(tmp[j + 1] - tmp[j] != tmp[1] - tmp[0])
                    is_arith = false;
            }
            res.push_back(is_arith);
        }

        return res;        
    }
};