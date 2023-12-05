// accepted
// https://atcoder.jp/contests/abc330/tasks/abc330_d
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

    int n;
    cin >> n;
    int ans = 0;
    vector<string> grid(n);
    vector<int> num_o_row(n);
    vector<int> num_o_col(n, 0);
    for(int i = 0; i < n; ++i) {
        cin >> grid[i];
        int count = 0;
        for(char c : grid[i]) {
            if(c == 'o') count++;
        }
        num_o_row[i] = count;

    }
    
    for(int c = 0; c < n; ++c) {
        for(int r = 0; r < n; ++r) {
            if(grid[r][c] == 'o') num_o_col[c]++;
        }
    }

    for(int r = 0; r < n; ++r) {
        for(int c = 0; c < n; ++c) {
            if(grid[r][c] == 'x') continue;
            int o_row = num_o_row[r] - 1;
            int o_col = num_o_col[c] - 1;

            if(o_row >= 1 && o_col >= 1) {
                ans += o_row * o_col;
            }

        }
    }

    cout << ans << "\n";

    return 0;
}
