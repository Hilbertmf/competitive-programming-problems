#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// #define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

bool iterateSubgrids(vector<vector<int>>& grid_a, 
                    vector<vector<int>>& grid_b, 
                    int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
        // Iterate through subgrids starting from current cell (i, j).
            for (int subgrid_size_i = 2; subgrid_size_i <= n - i; ++subgrid_size_i) {
                for (int subgrid_size_j = 2; subgrid_size_j <= m - j; ++subgrid_size_j) {
                    int end_i = i + subgrid_size_i - 1;
                    int end_j = j + subgrid_size_j - 1;

                    // Compare top-left and bottom-right corners of the subgrid.
                    int top_l_a = grid_a[i][j];
                    int top_l_b = grid_b[i][j];
                    int top_r_a = grid_a[i][end_j];
                    int top_r_b = grid_b[i][end_j];
                    int bottom_l_a = grid_a[end_i][j];
                    int bottom_l_b = grid_b[end_i][j];
                    int bottom_r_a = grid_a[end_i][end_j];
                    int bottom_r_b = grid_b[end_i][end_j];

                    if (abs(top_l_a - top_l_b) != abs(bottom_r_a - bottom_r_b) ||
                        abs(top_r_a - top_r_b) != abs(bottom_l_a - bottom_l_b))
                        return false;


                }
            }
        }
    }
    return true;
}


int32_t main() {
    FASTIO;
    int t;
    cin >> t;
    
    while(t--){

        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        vector<vector<int>> b(n, vector<int>(m));
        int sum_a = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                cin >> a[i][j];
                sum_a += a[i][j];
            }
        }
        int sum_b = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                cin >> b[i][j];
                sum_b += b[i][j];
            }
        }

        

        sum_a %= 3;
        sum_b %= 3;

        bool possible = sum_a == sum_b;
        if (possible)
            possible = iterateSubgrids(a, b, n, m);

        DEBUG(possible);

        if(possible) {
            cout << "YES" << "\n";
        }
        else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}

