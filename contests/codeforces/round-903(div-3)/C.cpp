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

pair<int, int> flip90deg(int r, int c, int rows, int cols) {
	return {c, cols - 1 - r};
}

int32_t main() { 
	FASTIO;
	int t;
	cin >> t;
	while (t--) {

		int n;
		cin >> n;
		vector<vector<char>> matrix(n, vector<char>(n));

		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				cin >> matrix[i][j];
			}
		}

		int max_num = 0;
		int sum = 0;
		vector<vector<bool>> vis(n, vector<bool>(n, false));

		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				if(vis[i][j]) continue;
				
				auto p1 = flip90deg(i, j, n, n);
				auto p2 = flip90deg(p1.first, p1.second, n, n);
				auto p3 = flip90deg(p2.first, p2.second, n, n);
				vector<int> vals(4);
				vals[0] = matrix[i][j];
				vals[1] = matrix[p1.first][p1.second];
				vals[2] = matrix[p2.first][p2.second];
				vals[3] = matrix[p3.first][p3.second];

				sort(vals.begin(), vals.end());
				sum += (vals.back() - vals[0]) + (vals.back() - vals[1]) + (vals.back() - vals[2]);

				vis[i][j] = true;
				vis[p1.first][p1.second] = true;
				vis[p2.first][p2.second] = true;
				vis[p3.first][p3.second] = true;

			}
		}

		cout << sum << "\n";
	}
	
	return 0; 
}
