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

    vector<vector<int>> grid(9, vector<int>(9));
    for(int i = 0; i < 9; ++i) {
        for(int j = 0; j < 9; ++j) {
            grid[i][j] = (i + 1) * (j + 1);
        }
    }

    int x;
    cin >> x;
    int ans = 0;
    for(int i = 0; i < 9; ++i) {
        for(int j = 0; j < 9; ++j) {
            if (grid[i][j] != x) ans += grid[i][j];
        }
    }


    cout << ans << "\n";

    return 0;
}
