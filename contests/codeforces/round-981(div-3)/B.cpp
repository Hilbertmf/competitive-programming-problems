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

        int n, ans = 0;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                cin >> grid[i][j];
            }
        }

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if (grid[i][j] < 0) {
                    int sm = grid[i][j];

                    // main diagonal
                    for(int r = i, c = j; r < n && c < n; ++r, ++c) {
                        sm = min(sm, grid[r][c]);
                        grid[r][c] = 0;
                    }
                    for(int r = i, c = j; r >= 0 && c >= 0; --r, --c) {
                        sm = min(sm, grid[r][c]);
                        grid[r][c] = 0;
                    }
                    ans += (-1 * sm);
                }
            }
        }

        cout << ans << "\n";
    }
    
    return 0;
}


 
