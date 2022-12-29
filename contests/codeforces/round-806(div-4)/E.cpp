#include <bits/stdc++.h> 
using namespace std; 
#define DEBUG(x) cout << #x << " >>>> " << x << endl 
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 


bool middle(int row, int col, vector<vector<char>>& grid) {
    return (grid.size() & 1 && grid[0].size() & 1) &&
    (row == grid.size() / 2 && col == grid[0].size() / 2);
}

int main() { 
    FASTIO;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<char>> grid(n, vector<char>(n));
        vector<vector<bool>> visited(n, vector<bool>(n));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                cin >> grid[i][j];
            }
        }

        int ans = 0;

        
        for(int r = 0; r < n; ++r) {
            for(int c = 0; c < n; ++c) {
                if(grid[r][c] == '1' && !visited[r][c] && !middle(r, c, grid)) {
                    visited[r][c] = true;
                    int ones = 1;
                    
                    if(grid[c][n - 1 - r] == '1') ones++;
                    visited[c][n - 1 - r] = true;
                    if(grid[n - 1 - r][n - 1 - c] == '1') ones++;
                    grid[n - 1 - r][n - 1 - c] = true;
                    if(grid[n - 1 - c][r] == '1') ones++;
                    grid[n - 1 - c][r] = true;

                    if(ones >= 2) ans += 4 - ones;
                    else ans += ones;
                }
            }
        }

        cout << ans << "\n";
    }	
    
    return 0; 
}
