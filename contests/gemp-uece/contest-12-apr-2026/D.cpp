// AC
// https://codeforces.com/problemset/problem/263/A
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

    int grid[5][5];
    pair<int, int> pos;

    for(int i = 0; i < 5; ++i) {
        for(int j = 0; j < 5; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 1) pos = {i, j};
        }
    }

    cout << abs(pos.first - 2) + abs(pos.second - 2) << "\n";

    

    return 0;
}
