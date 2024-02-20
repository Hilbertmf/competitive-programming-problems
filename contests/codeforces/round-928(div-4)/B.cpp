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
        vector<vector<char>> grid(n, vector<char>(n));
        pair<int, int> start = {-1, -1};

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                cin >> grid[i][j];
                if(grid[i][j] == '1' && start.first == -1) {
                    start = {i, j};
                }
            }
        }

        bool square = true;
        bool found = false;
        int sq_side = 0;
        int last = -1;
        bool interrupt = false;
        int last_col = n - 1;

        for(int col = start.second; col < n; ++col) {
            if(grid[start.first][col] != '1') {
                last_col = col - 1;
                break;
            }
            sq_side++;
        }

        for(int i = start.first + 1; i < n && i <= start.first + sq_side - 1; ++i) {
            
            for(int j = 0; j < start.second; ++j) {
                if(grid[i][j] == '1') {
                    square = false;
                    break;
                }
            }
            
            for(int j = start.second; j <= last_col; ++j) {
                if(grid[i][j] != '1') {
                    square = false;
                    break;
                }
            }

            for(int j = last_col + 1; j < n; ++j) {
                if(grid[i][j] == '1') {
                    square = false;
                    break;
                }
            }
        }

        for(int i = start.first + sq_side; i < n && square; ++i) {
            for(int j = 0; j < n && square; ++j) {
                if(grid[i][j] == '1') {
                    square = false;
                    break;
                }
            }
        }


        if(square) {
            cout << "SQUARE" << "\n";
        }
        else {
            cout << "TRIANGLE" << "\n";
        }

    }
    
    return 0;
}
