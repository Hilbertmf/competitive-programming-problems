// acc
// contest: https://vjudge.net/contest/540086#overview
#include <bits/stdc++.h> 
using namespace std; 
#define DEBUG(x) cout << #x << " >>>> " << x << endl 
#define MID(l, r) (l + (r - l) / 2) 
#define CEILDIVISION(x, y) ((x + y - 1) / y) 
#define INF (int)1e9 
#define LONGINF (long long)1e18 
#define MEM(arr, val) memset(arr, (val), sizeof(arr)) 
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
#define int long long
const int MOD = 1000000007; // 10^9 - 7 

int32_t main() { 
	FASTIO;
	int n, m;
	cin >> n >> m;
	vector<vector<int>> grid(n, vector<int>(m));

	int sum = 0;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			cin >> grid[i][j];

	for(int i = n - 1; i >= 0; --i) {
		for(int j = m - 1; j >= 0; --j) {
			if(grid[i][j] == 0) 
				grid[i][j] = min(grid[i+1][j], grid[i][j+1]) - 1;
			sum += grid[i][j];
		}
	}

	bool possible = true;

	for(int i = 0; i < n && possible; ++i)
		for(int j = 0; j < m - 1 && possible; ++j)
			if(grid[i][j] >= grid[i][j + 1]) possible = false;

	for(int i = 0; i < m && possible; ++i)
		for(int j = 0; j < n - 1 && possible; ++j)
			if(grid[j][i] >= grid[j + 1][i]) possible = false;

	if(possible)
		cout << sum << "\n";
	else
		cout << "-1\n";

	return 0; 
}
