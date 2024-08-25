// time: O(n)
// space: O(1)
#include <bits/stdc++.h>
using namespace std;
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int MOD = 1e9 + 7; // 10^9 + 7

int main() {
    FASTIO;

    int n;
    cin >> n;
    
    long long max_sum = -INF, sum = 0;
    long long max_elem = -INF;
    for(int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        max_elem = max(max_elem, (long long)num);
        if(sum + num < 0)
            sum = 0;
        else
            sum += num;
        
        if(sum > 0)
            max_sum = max(max_sum, sum);
    }

    cout << max(max_sum, max_elem) << "\n";

    return 0;
}

// time: O(n²*m²)
// space: O(n*m)
/*
calculate 2d prefix sum, then generate every submatrix from 0,0 to i,j
if sum of that submatrix == target then increment count. The sum can be obtained
w/ the 2d prefix sum in O(1) time
Do this for every row i and col
*/
class Solution {
public:
    
    void populatePrefix2D(vector<vector<int>>& grid, vector<vector<int>>& prefix) {

        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i < n; ++i) {
            long long sum = 0;
            for(int j = 0; j < m; ++j) {

                prefix[i][j] = grid[i][j];
                if(i > 0)
                    prefix[i][j] += prefix[i - 1][j];
                if(j > 0)
                    prefix[i][j] += sum;

                sum += grid[i][j];
            }
        }

    }
    
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>> prefix(rows, vector<int>(cols));
        populatePrefix2D(matrix, prefix);
        int count = 0;

        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < cols; ++j) {
                for(int r = 0; r <= i; ++r) {
                    for(int c = 0; c <= j; ++c) {

                        int submatrix_sum = prefix[i][j];
                        int removals = 0;
                        if(r > 0) {
                            submatrix_sum -= prefix[r - 1][j];
                            removals++;
                        }
                        if(c > 0) {
                            submatrix_sum -= prefix[i][c - 1];
                            removals++;
                        }
                        if(removals == 2 && r > 0 && c > 0)
                            submatrix_sum += prefix[r - 1][c - 1];

                        if(submatrix_sum == target)
                            count++;
                    }
                }
            }
        }
        
        return count;
    }
};