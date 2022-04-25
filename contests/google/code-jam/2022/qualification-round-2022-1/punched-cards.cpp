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
	std::cin >> t;
	for(int test = 0; test < t; test++) {
		int r, c;
		std::cin >> r >> c;
		char grid[2*r + 1][2*c + 1];

		for(int i = 0; i < 2*r+1; i++) {
			for(int j = 0; j < 2*c+1; j++) {
				// if(leftTop[i] == j) continue;
				if(i % 2 == 0) {
					if(j % 2 == 0) {
						grid[i][j] = '+';
					}
					else {
						grid[i][j] = '-';
					}
				}
				else {
					if(j % 2 == 0) {
						grid[i][j] = '|';
					}
					else {
						grid[i][j] = '.';
					}
				}
			}
		}
		grid[0][0] = '.';
		grid[0][1] = '.';
		grid[1][0] = '.';
		grid[1][1] = '.';
		
		cout << "Case #" << test+1 << ":" << endl;
		for(int i = 0; i < 2*r+1; i++) {
			for(int j = 0; j < 2*c+1; j++) {
				cout << grid[i][j];
			}
			cout << "\n";
		}
	}
	
	return 0; 
}
