// https://atcoder.jp/contests/abc378/tasks/abc378_d
// AC
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

vector<int> dr {1, -1, 0, 0};
vector<int> dc {0, 0, 1, -1};

int ans = 0, K = 0;
bool valid(int r, int c, int rows, int cols) {
    return r >=0 && r < rows && c >=0 && c < cols;
}

void backtrack(int r, int c, vector<vector<char>>& grid, vector<vector<char>>& vis, int moves) {
    int rows = grid.size(), cols = grid[0].size();

    if (moves == K) {
        ans++;
        return;
    }

    for(int i = 0; i < 4; ++i) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (!valid(nr, nc, rows, cols) || grid[nr][nc] == '#' || vis[nr][nc])
            continue;

        vis[nr][nc] = true;
        backtrack(nr, nc, grid, vis, moves + 1);
        vis[nr][nc] = false;
    }
}

int32_t main() {
    FASTIO;

    int rows, cols, k;
    cin >> rows >> cols >> k;
    K = k;
    vector<vector<char> > grid(rows, vector<char>(cols));

    for(int i = 0; i < rows; ++i)
        for(int j = 0; j < cols; ++j)
            cin >> grid[i][j];

    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            if (grid[i][j] == '#') continue;
            vector<vector<char>> vis(rows, vector<char>(cols));
            vis[i][j] = true;
            backtrack(i, j, grid, vis, 0);
        }
    }

    cout << ans << "\n";
    return 0;
}
