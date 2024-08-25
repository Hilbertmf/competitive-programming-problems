// https://cses.fi/problemset/task/1672/
// accepted
// floyd-warshall algorithm
// time: O(n³)
// space: O(n² + m)
#include <bits/stdc++.h> 
using namespace std; 
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
#define int long long
#define INF (int)1e18
const int MOD = 1000000007; // 10^9 - 7

vector<vector<int>> dist;

void floydWarshall(int n, vector<vector<pair<int, int>>>& graph) {
    dist = vector<vector<int>> (n, vector<int>(n, INF));
    for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			if(i == j) dist[i][j] = 0;
			else {
				for(auto &edge : graph[i]) {
					if (edge.first == j)
						dist[i][j] = min(dist[i][j], edge.second);
				}
			}
		}
    }   

    for(int mid = 0; mid < n; ++mid) {
        for(int from = 0; from < n; ++from) {
            for(int to = 0; to < n; ++to) {
                if (dist[from][mid] != INF && dist[mid][to] != INF)
                    dist[from][to] = min(dist[from][to],
                                         dist[from][mid] + dist[mid][to]);
            }
        }
    }
}

void readWeightedGraphUndir(vector<vector<pair<int, int>>>& graph, int num_edges);

int32_t main() { 

    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<pair<int, int>>> graph(n);
    readWeightedGraphUndir(graph, m);

	floydWarshall(n, graph);

	while (q--) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		if(dist[u][v] == INF)
			cout << -1 << "\n";
		else
			cout << dist[u][v] << "\n";
	}
	
	return 0; 
}

void readWeightedGraphUndir(vector<vector<pair<int, int>>>& graph, int num_edges) {
    for(int i = 0; i < num_edges; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
}