#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

bool isSafe(int r, int c, vector<string>& grid) {    
    if (grid[r][c] == '#') return false;
    for(int i = 0; i < 8; ++i) {
        if (i == r) continue;
        if (grid[i][c] == '#') return false;
    }
    for(int i = 0; i < 8; ++i) {
        if (i == c) continue;
        if (grid[r][i] == '#') return false;
    }
    return true;
}

int32_t main() {
    FASTIO;

    vector<string> grid(8);
    for(int i = 0; i < 8; ++i) {
        cin >> grid[i];
    }

    int count = 0;


    for(int i = 0; i < 8; ++i) {
        for(int j = 0; j < 8; ++j) {
            if (isSafe(i, j, grid))
                count++;
        }
    }


    cout << count << "\n";

    return 0;
}
