// https://cses.fi/problemset/task/1671/
// accepted
// time: O(E*logE)
// space: O(V + E)
#include <bits/stdc++.h> 
using namespace std; 
#define DEBUG(x) cout << #x << " >>>> " << x << endl 
#define int long long
#define INF (long long)1e17

vector<int> dijkstra(vector<vector<pair<int, int>>>& graph, int start) {
	int n = graph.size();
	vector<int> dists(n, INF);
	dists[start] = 0;
	// max heap by default, so negate the dists
	priority_queue<pair<int, int>> heap;
	heap.push({0, start}); // dist, vertex
	vector<char> vis(n);

	while(!heap.empty()) {
		int dist = -heap.top().first;
		int v = heap.top().second;
		heap.pop();

		if (vis[v]) continue;
		vis[v] = true;

		for(auto &[adj, w] : graph[v]) {
			if(dists[adj] > dists[v] + w) {
				dists[adj] = dists[v] + w;
				heap.push({-dists[adj], adj});
			}
		}
	}
	return dists;
}

void readWeightedGraphDir(vector<vector<pair<int, int>>>& graph, int num_edges);

int32_t main() {

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n);
    vector<int> in_degree(n);
    readWeightedGraphDir(graph, m);

	vector<int> dists = dijkstra(graph, 0);

	for(auto &dist : dists) {
		cout << dist << " ";
	}
	
	return 0;
}

void readWeightedGraphDir(vector<vector<pair<int, int>>>& graph, int num_edges) {
    for(int i = 0; i < num_edges; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        graph[u].push_back({v, w});
    }
}
