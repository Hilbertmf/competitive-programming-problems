#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

bool valid(int r, int c, vector<vector<char>>& grid) {
    return r >= 0 && r < grid.size() &&
           c >= 0 && c < grid[0].size();
}

int32_t main() {
    FASTIO;
    
    int n, m, k, l;
    cin >> n >> m >> k >> l;

    k--;
    l--;

    vector<int> dr {k, k, -k, -k, l, -l, l, -l};
    vector<int> dc {l, -l, l, -l, k, k, -k, -k};

    vector<vector<char>> grid(n, vector<char>(m));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    int best = 0;
    pair<int, int> ans {INF, INF};

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if (grid[i][j] != '.') continue;
            int curr = 0;
            for(int k = 0; k < 8; ++k) {
                int nr = i + dr[k];
                int nc = j + dc[k];
                if (!valid(nr, nc, grid)) continue;
                if (grid[nr][nc] == '*')
                    curr++;
            }
            
            if (curr >= best) {
                
                if (curr == best)
                    ans = min(ans, {i, j});
                else
                    ans = {i, j};
                best = curr;
            }
        }
    }

    cout << ans.first + 1 << " " << ans.second + 1 << "\n";


    return 0;
}
