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

        int n;
        cin >> n;
        string s;
        cin >> s;
        int rows = 0;
        int cols = 0;
        
        int idx = 0;
        while (idx < n && s[idx] == '1') {
            idx++;
        }
        cols = idx - 1;

        vector<vector<char>> grid(cols, vector<char>(cols, '0'));

        for(int c = 0; c < cols; ++c) {
            grid[0][c] = '1';
            grid[cols - 1][c] = '1';
        }

        for(int r = 0; r < cols; ++r) {
            grid[r][0] = '1';
            grid[r][cols - 1] = '1';
        }

        string cmp;
        for(int i = 0; i < cols; ++i) {
            for(int j = 0; j < cols; ++j) {
                cmp += grid[i][j];
            }
        }

        bool pos = cmp == s;

        int count0 = count(s.begin(), s.end(), '0');
        if (s.size() == 1)
            pos = true;
        else if (count0 == 0) {
            pos |= (s.size() == 4);
        }
        
        if(pos) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }


    }
    
    return 0;
}
