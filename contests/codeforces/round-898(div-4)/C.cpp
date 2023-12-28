#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

void initGrid(vector<vector<int>>& pts_grid) {

    for(int i = 0; i < 5; ++i) {
        fill(pts_grid[i].begin(), pts_grid[i].end(), i + 1);
        fill(pts_grid[9 - i].begin(), pts_grid[9 - i].end(), i + 1);
    }

    for(int j = 0; j < 5; ++j) {
        for(int i = j; i < 5; ++i) {
            pts_grid[i][j] = j + 1;
            pts_grid[i][9 - j] = j + 1;
            pts_grid[9 - i][j] = j + 1;
            pts_grid[9 - i][9 - j] = j + 1;
        }
    }

}

int32_t main() {
    FASTIO;
    int t;
    cin >> t;
    
    while(t--){

        vector<string> grid(10);
        int points = 0;

        vector<vector<int>> pts_grid(10, vector<int>(10));
        initGrid(pts_grid);
        
        for(int i = 0; i < 10; ++i) {
            cin >> grid[i];
            for(int j = 0; j < grid[i].size(); ++j) {
                if(grid[i][j] == 'X') {
                    points += pts_grid[i][j];
                }
            }
        }

        cout << points << "\n";

    }
    
    return 0;
}
