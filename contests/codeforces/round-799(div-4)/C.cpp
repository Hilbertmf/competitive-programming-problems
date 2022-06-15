#include <bits/stdc++.h> 
using namespace std; 
#define DEBUG(x) cout << #x << " >>>> " << x << endl 
#define MID(l, r) (l + (r - l) / 2) 
#define CEILDIVISION(x, y) ((x + y - 1) / y) 
#define INF (int)1e9 
#define LONGINF (long long)1e18 
#define MEM(arr, val) memset(arr, (val), sizeof(arr)) 
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
const int MOD = 1000000007; // 10^9 - 7 

vector<int> dr{1, -1, 1, -1};
vector<int> dc{1, -1, -1, 1};

int main() { 
    FASTIO;
    int t;
    cin >> t;
    while (t--) {
        bool bishop = false;

        vector<vector<char>> board(8, vector<char>(8));
        pair<int, int> ans;
        for(int i = 0; i < 8 && !bishop; ++i) {
            for(int j = 0; j < 8 && !bishop; ++j) {
                cin >> board[i][j];
            }
        }

        for(int i = 0; i < 8 && !bishop; ++i) {
            for(int j = 0; j < 8 && !bishop; ++j) {
                
                if(i > 0 && i < 8 && j > 0 && j < 8 && board[i][j] == '#' &&
                board[i + dr[0]][j + dc[0]] == '#' && board[i + dr[1]][j + dc[1]] == '#' &&
                board[i + dr[2]][j + dc[2]] == '#' && board[i + dr[3]][j + dc[3]] == '#') {
                    bishop = true;
                }
                if(bishop) {
                    ans = {i, j};
                    break;
                }
            }
        }


        cout << ans.first + 1 << " " << ans.second + 1<< "\n";
    }	
    
    return 0; 
}
