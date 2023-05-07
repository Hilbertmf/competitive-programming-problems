// https://cses.fi/problemset/task/1672/
// accepted
// floyd-warshall algorithm
// time: O(n³)
// space: O(n² + m)
#include <bits/stdc++.h> 
using namespace std; 
#define DEBUG(x) cout << #x << " >>>> " << x << endl 
#define MID(l, r) (l + (r - l) / 2) 
#define CEILDIVISION(x, y) ((x + y - 1) / y) 
#define LONGINF (long long)1e17 
#define MEM(arr, val) memset(arr, (val), sizeof(arr)) 
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
#define int long long
#define INF (int)1e17 
const int MOD = 1000000007; // 10^9 - 7

void floyd_warshall(vector<vector<int>>& edges, vector<vector<int>>& dp, int n) {
	
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			if(i == j)
				dp[i][j] = 0;
		}
	}

	for(auto &vec : edges) {
		int u = vec[0], v = vec[1], w = vec[2];
		dp[u][v] = min(dp[u][v], w);
	}

	for(int k = 1; k <= n; ++k) {
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= n; ++j) {			
				int exclude = dp[i][j];
				int include = dp[i][k] + dp[k][j];
				dp[i][j] = min(exclude, include);
			}
		}
	}
}

int32_t main() { 
	FASTIO;
	int n, m, q;
	cin >> n >> m >> q;
	
	vector<vector<pair<int, int>>> graph(n+1);
	vector<vector<int>> dists(n+1, vector<int>(n+1, INF));

	vector<vector<int>> edges;
	edges.reserve(m*2);
	for(int i = 0; i < m; ++i) {
		int u, v;
		int w;
		cin >> u >> v >> w;

		edges.push_back({u, v, w});
		edges.push_back({v, u, w});
	}

	floyd_warshall(edges, dists, n);

	while (q--) {
		int u, v;
		cin >> u >> v;
		if(dists[u][v] == INF)
			cout << -1 << "\n";
		else
			cout << dists[u][v] << "\n";
	}
	
	return 0; 
}
