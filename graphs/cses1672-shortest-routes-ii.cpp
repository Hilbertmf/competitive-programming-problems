#include <bits/stdc++.h> 
using namespace std; 
#define DEBUG(x) cout << #x << " >>>> " << x << endl 
#define MID(l, r) (l + (r - l) / 2) 
#define CEILDIVISION(x, y) ((x + y - 1) / y) 
#define INF (int)1e9 
#define LONGINF (long long)1e17 
#define MEM(arr, val) memset(arr, (val), sizeof(arr)) 
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
const int MOD = 1000000007; // 10^9 - 7 

void dijkstra(vector<vector<pair<int, long long>>>& graph,
vector<vector<long long>>& dists, int src) {
	dists[src][src] = 0;
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
	pq.push({0, src});

	while(!pq.empty()) {
		long long dist = pq.top().first;
		int v = pq.top().second;
		pq.pop();

		if(v < src) {
			dists[src][v] = dists[v][src];
			continue;
		}
		if(dist != dists[src][v]) continue;

		for(auto &[u, w] : graph[v]) {
			if(dists[src][v] + w < dists[src][u]) {
				dists[src][u] = dists[src][v] + w;
				pq.push({dists[src][u], u});
			}
		}
	}

	for(auto &dist : dists[src]) {
		if(dist == LONGINF) dist = -1;
	}
}

int32_t main() { 
	FASTIO;
	int n, m, q;
	cin >> n >> m >> q;

	vector<vector<pair<int, long long>>> graph(n+1);
	vector<vector<long long>> dists(n+1, vector<long long>(n+1, LONGINF));

	for(int i = 0; i < m; ++i) {
		int u, v;
		long long w;
		cin >> u >> v >> w;
		graph[u].push_back({v, w});
		graph[v].push_back({u, w});
	}

	for(int v = 1; v <= n; ++v) {
		dijkstra(graph, dists, v);

		for(int u = v + 1; u <= n; ++u) {
			dists[u][v] = dists[v][u];
		}
	}

	while (q--) {
		int u, v;
		cin >> u >> v;
		if(dists[u][v] == LONGINF)
			cout << -1 << "\n";
		else
			cout << dists[u][v] << "\n";
	}
	
	return 0; 
}
