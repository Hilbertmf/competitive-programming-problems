// https://codeforces.com/contest/1994/problem/A
// ac
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
        vector<vector<int>> grid(n, vector<int>(m));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                cin >> grid[i][j];
            }
        }

        bool possible = n > 1 || m > 1;
        vector<vector<int>> grid2(n, vector<int>(m));

        if(possible) {        
            if(m == 1) {
                for(int i = 0; i < n; ++i) {
                    if (i + 1 >= n)
                        grid2[i][0] = grid[0][0];
                    else
                        grid2[i][0] = grid[i + 1][0];
                }
            }
            else {
                for(int i = 0; i < n; ++i) {
                    for(int j = 0; j < m; ++j) {
                        if (j + 1 >= m)
                            grid2[i][j] = grid[i][0];
                        else
                            grid2[i][j] = grid[i][j + 1];
                    }
                }
            }
            
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < m; ++j) {
                    if (j > 0) cout << " ";
                    cout << grid2[i][j];
                }
                cout << "\n";
            }

        }
        else {
            cout << "-1\n";
        }
    }
    
    return 0;
}
