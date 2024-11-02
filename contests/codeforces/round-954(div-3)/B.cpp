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

bool valid(int r, int c, vector<vector<int>>& grid) {
    return r >= 0 && r < grid.size() &&
           c >= 0 && c < grid[0].size();
}

int32_t main() {
    FASTIO;
    int t;
    cin >> t;
    
    while(t--){

        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        int min_elem = INF;

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                cin >> grid[i][j];
                min_elem = min(min_elem, grid[i][j]);
            }
        }

        while (true) {
            bool can_finish = true;
            int count = 0;

            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < m; ++j) {
                    // test
                    int val = grid[i][j];
                    int max_adj = -INF;
                    for(int k = 0; k < 4; ++k) {
                        int nr = i + dr[k];
                        int nc = j + dc[k];
                        if (!valid(nr, nc, grid)) continue;
                        max_adj = max(max_adj, grid[nr][nc]);
                    }

                    if (val > max_adj) {
                        grid[i][j] = max_adj;
                        can_finish = false;
                    }
                }
            }

            if (can_finish) break;
        }

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                cout << grid[i][j] << " ";
            }
            cout << "\n";
        }
    }
    
    return 0;
}
