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
 
int main() { 
    FASTIO;
    int t;
    cin >> t;
    while (t--) {
        vector<vector<int>> grid(2, vector<int>(2));

        int numGrass = 0;
        int moves = 0;
        for(int i = 0; i < 2; ++i) {
            for(int j = 0; j < 2; ++j) {
                cin >> grid[i][j];
                if(grid[i][j] == 1) numGrass++;
            }
        }

        if(numGrass == 0) {
            cout << 0 << "\n";
        }
        else if(numGrass > 0 && numGrass < 4) {
            cout << 1 << "\n";
        }
        else {
            cout << 2 << "\n";
        }
        
    }	
    
    return 0; 
}
