// acc
// https://codeforces.com/contest/1985/problem/D
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

int32_t main() {
    FASTIO;
    int t;
    cin >> t;
    
    while(t--){

        int n, m;
        cin >> n >> m;
        int max_x = -INF, min_x = INF;
        int max_y = -INF, min_y = INF;
        vector<vector<char>> grid(n, vector<char>(m));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                cin >> grid[i][j];
                if (grid[i][j] == '#') {
                    max_x = max(i, max_x);
                    min_x = min(i, min_x);
                    max_y = max(j, max_y);
                    min_y = min(j, min_y);
                }
            }
        }
        int center_x = (max_x + min_x) / 2;
        int center_y = (max_y + min_y) / 2;
        cout << center_x + 1 << " " << center_y + 1 << "\n";
    }
    
    return 0;
}
