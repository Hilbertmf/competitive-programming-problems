// https://cses.fi/problemset/task/1652/
// time: O(q + n²)
// space: O(n²)
#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main() {
    FASTIO;

    int n, q;
    cin >> n >> q;
    vector<vector<int>> grid(n, vector<int>(n));
    vector<vector<long long>> prefix(n, vector<long long>(n));
    for(int i = 0; i < n; ++i) {
        long long sum = 0;
        for(int j = 0; j < n; ++j) {
            char c;
            cin >> c;
            if(c == '.') {
                grid[i][j] = 0;
            }
            else {
                grid[i][j] = 1;
            }

            prefix[i][j] = grid[i][j];
            if(i > 0)
                prefix[i][j] += prefix[i - 1][j];
            if(j > 0)
                prefix[i][j] += sum;

            sum += grid[i][j];
        }
    }

    while (q--) {
        int x1, x2, y1, y2;
        cin >> y1 >> x1 >> y2 >> x2;
        x1--; y1--; x2--; y2--;
        int removals = 0;

        long long ans = prefix[y2][x2];
        if(y1 > 0) {
            ans -= prefix[y1 - 1][x2];
            removals++;
        }
        if(x1 > 0) {
            ans -= prefix[y2][x1 - 1];
            removals++;
        }
        if(removals == 2) { // removed that part twice
            ans += prefix[y1 - 1][x1 - 1];
        }

        cout << ans << "\n";
    }
        
    return 0;
}
