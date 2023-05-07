// https://cses.fi/problemset/task/1671/
// accepted
// time: O(m*logm)
// space: O(m + n)
#include <bits/stdc++.h> 
using namespace std; 
#define DEBUG(x) cout << #x << " >>>> " << x << endl 
#define MID(l, r) (l + (r - l) / 2) 
#define CEILDIVISION(x, y) ((x + y - 1) / y) 
#define INF (long long)1e17
#define LONGINF (long long)1e18 
#define MEM(arr, val) memset(arr, (val), sizeof(arr)) 
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
#define int long long
const int MOD = 1000000007; // 10^9 - 7 

vector<int> dijkstra(vector<vector<pair<int, int>>>& graph, int s) {
	int n = graph.size();
	vector<int> dists(n, INF);
	dists[s] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, s}); // dist, vertex

	while(!pq.empty()) {
		int dist = pq.top().first;
		int v = pq.top().second;
		pq.pop();

		if(dists[v] != dist) continue;

		for(auto &[u, w] : graph[v]) {
			if(dists[u] > dists[v] + w) {
				dists[u] = dists[v] + w;
				pq.push({dists[u], u});
			}
		}
	}
	return dists;
}

int32_t main() { 
	FASTIO;
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> graph(n);

	for(int i = 0; i < m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		--u;
		--v;
		graph[u].push_back({v, w});
	}

	vector<int> dists = dijkstra(graph, 0);

	for(auto &dist : dists) {
		cout << dist << " ";
	}
	
	return 0; 
}
