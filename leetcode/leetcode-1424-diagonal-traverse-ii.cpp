class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {

        vector<int> res;
        vector<vector<int>> matrix;

        for(int r = 0; r < nums.size(); ++r) {
            for(int c = 0; c < nums[r].size(); ++c) {
                if(r + c < matrix.size())
                    matrix[r + c].push_back(nums[r][c]);
                else
                    matrix.push_back({nums[r][c]});
            }
        }

        for(int r = 0; r < matrix.size(); ++r) {
            for(int c = matrix[r].size() - 1; c >= 0; --c) {
                res.push_back(matrix[r][c]);
            }
        }

        return res;
    }
};
