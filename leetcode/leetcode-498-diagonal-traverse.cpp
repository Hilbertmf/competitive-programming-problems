class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
            
        vector<int> res;
        int direction = 0;

        for(int r = 0; r < mat.size() + mat[0].size(); ++r) {
            int cr = r;
            int col_start = 0;
            if(cr >= mat.size()) {
                col_start = cr - mat.size() + 1;
                cr = mat.size() - 1;
            }

            vector<int> tmp;
            for(int c = col_start; c < mat[0].size() && cr >= 0; ++c, --cr) {
                if(c < mat[0].size() && cr >= 0)
                    tmp.push_back(mat[cr][c]);
            }

            if(direction)
                reverse(tmp.begin(), tmp.end());
            direction ^= 1;
            
            res.insert(res.end(), tmp.begin(), tmp.end());
        }

        return res;

    }
};