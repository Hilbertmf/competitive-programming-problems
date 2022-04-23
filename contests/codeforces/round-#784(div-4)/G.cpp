// solved
// https://codeforces.com/contest/1669/problem/G
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
 
void dfs(int r, int c, char grid[50][50], int row, int col) {
	// if in bounds and equals to dot: go down
	if((r < row && r >= 0) && grid[r][c] == '.') 
		dfs(r+1, c, grid, row, col);
	else { // else: out of bounds, stone or obstacle
		grid[r-1][c] = '*';
		return;
	}
}

int main() { 
	FASTIO;
	int t;
	std::cin >> t;
	while (t--) {
		int row, col;
		std::cin >> row >> col;
		char grid[50][50];
		
		for(int r = 0; r < row; r++) {
			for(int c = 0; c < col; c++) {
				std::cin >> grid[r][c];
			}
		}

		for(int r = row - 2; r >= 0; r--) {
			for(int c = 0; c < col; c++) {
				if(grid[r][c] == '*') {
					grid[r][c] = '.';
					dfs(r+1, c, grid, row, col);
				}
			}
		}
		
		for(int r = 0; r < row; r++) {
			for(int c = 0; c < col; c++) {
				std::cout << grid[r][c];
			}
			std::cout << std::endl;
		}
	}
	return 0; 
}
