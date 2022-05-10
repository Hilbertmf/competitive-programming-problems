// accepted
// https://codeforces.com/contest/1676/problem/D
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

long long getSumDiag(int r, int c, long long board[200][200], int rows, int cols) {
	long long sum = 0;
	for(int i = r + 1, j = c + 1; i < rows && j < cols; ++i, ++j) {
		sum += board[i][j];
	}
	for(int i = r - 1, j = c - 1; i >= 0 && j >= 0; --i, --j) {
		sum += board[i][j];
	}
	for(int i = r + 1, j = c - 1; i < rows && j >= 0; ++i, --j) {
		sum += board[i][j];
	}
	for(int i = r - 1, j = c + 1; i >= 0 && j < cols; --i, ++j) {
		sum += board[i][j];
	}
	return sum + board[r][c];
}

int main() { 
	FASTIO;
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		long long board[200][200];
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				cin >> board[i][j];
			}
		}

		long long sum = 0;
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				sum = max(sum, getSumDiag(i, j, board, n, m));
			}
		}
		cout << sum << endl;
	}	
	
	return 0; 
}
