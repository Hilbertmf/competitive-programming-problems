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
    int tests;
    cin >> tests;
    for(int t = 1; t <= tests; ++t) {
		string ans = "Possible";
		int rows, cols;
		int numTrees = 0;
		cin >> rows >> cols;
		vector<vector<char>> grid(rows, vector<char>(cols));
		for(int r = 0; r < rows; ++r) {
			for(int c = 0; c < cols; ++c) {
				cin >> grid[r][c];
				if(grid[r][c] == '^') numTrees++;
			}
		}

		if((rows == 1 || cols == 1) && numTrees > 0) ans = "Impossible";
		else if(numTrees > 0) {
			for(int r = 0; r < rows; ++r) {
				for(int c = 0; c < cols; ++c) {
					grid[r][c] = '^';
				}
			}
		}

        cout << "Case #" << t << ": " << ans << "\n";
		if(ans == "Possible") {
			for(int r = 0; r < rows; ++r) {
				for(int c = 0; c < cols; ++c) {
					cout << grid[r][c];
				}
				cout << "\n";
			}
		}
    }	

	
	return 0; 
}
