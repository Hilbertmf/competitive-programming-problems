// AC
// https://codeforces.com/gym/105327/problem/E
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

vector<vector<int>> unrotate_90deg(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<vector<int>> res(n, vector<int>(n));

    for(int i = 0, j = n - 1; i < n; ++i, --j) {
        // col j equal  to row i
        for(int k = 0; k < n; ++k) {
            res[i][k] = grid[k][j];
        }
    }
    return res;
}

bool check(vector<vector<int>>& grid) {
    bool res = true;
    int n = grid.size();

    for(int i = 0; i < n; ++i) {
        vector<int> row;
        for(int j = 0; j < n; ++j) {
            row.push_back(grid[i][j]);
        }
        vector<int> sorted = row;
        sort(sorted.begin(), sorted.end());
        if (sorted != row) return false;
    }    

    for(int i = 0; i < n; ++i) {
        vector<int> col;
        for(int j = 0; j < n; ++j) {
            col.push_back(grid[j][i]);
        }
        vector<int> sorted = col;
        sort(sorted.begin(), sorted.end());
        if (sorted != col) return false;
    }

    return res;
}

int32_t main() {
    FASTIO;

    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }
    
    int i = 0;

    if(check(grid)) {
        cout << 0 << "\n";
    }
    else {
        for(i = 0; i < 4; ++i) {
            grid = unrotate_90deg(grid);
            if (check(grid)) {
                break;
            }
        }

        i++;
        cout << i << "\n";
    }

    return 0;
}
