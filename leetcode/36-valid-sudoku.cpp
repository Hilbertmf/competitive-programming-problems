class Solution {
public:
    bool isValid(vector<vector<char>>& matrix, int rowStart, int rowEnd, int colStart, int colEnd) {
        unordered_set<char> charsSet;
        for(int r = rowStart; r < rowEnd; ++r) {
            for(int c = colStart; c < colEnd; ++c) {
                char curr = matrix[r][c];
                if(charsSet.find(curr) != charsSet.end()) return false;
                else if(curr != '.') charsSet.insert(curr);
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>> matrix) {
        // rows
        for(int r = 0; r < matrix.size(); ++r) {
           if(!isValid(matrix, r, r+1, 0, matrix[r].size())) 
               return false;
        }

        //cols
        for(int r = 0; r < matrix.size(); ++r) {
            if(!isValid(matrix, 0, matrix[0].size(), r, r+1))
                return false;
        }

        //sub-boxes
        for(int i = 0; i <= matrix.size() - 3; i+= 3) {
            for(int j = 0; j <= matrix[0].size() - 3; j+= 3) {
                if(!isValid(matrix, i, i+3, j, j+3)) return false;
            }
        }

        return true;
    }
};