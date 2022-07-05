// accepted
// https://neps.academy/br/competition/1356/exercise/1324
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

long long dijkstra(int source, int destination, vector<list<pair<int, int>>> graph) {
	int numNodes = graph.size();
	vector<bool> visited(numNodes);
	vector<long long> dists(numNodes, LONGINF);
	dists[source] = 0;
	visited[source] = true;
	priority_queue<pair<long long, int>, vector<pair<long long, int>>,
	greater<pair<long long, int>>> pq;
	pq.push({0, source});

	while(!pq.empty()) {
		long long dist = pq.top().first;
		int node = pq.top().second;
		pq.pop();

        visited[node] = true;
		if(node == destination) return dist;

		for(auto &[neighbor, weight] : graph[node]) {
			if(visited[neighbor]) continue;

			if(dists[neighbor] > dist + weight)
                dists[neighbor] = dist + weight;
			pq.push({dist + weight, neighbor});
		}
	}

	return -1;
}

int main() { 
	FASTIO;
	int c, v;
	cin >> c >> v;
	vector<list<pair<int, int>>> graph(c);

	for(int i = 0; i < v; ++i) {
		int c1, c2, w;
		cin >> c1 >> c2 >> w;
		c1--;
		c2--;
		graph[c1].push_back({c2, w});
		graph[c2].push_back({c1, w});
	}

	vector<list<pair<int, int>>> graph2(2*c + 10);

	for(int i = 0; i < c; ++i) {

		for(auto &[node, weight] : graph[i]) {
			graph2[i*2 + 1].push_back({node*2 + 2, weight}); // v_odd
			graph2[i*2 + 2].push_back({node*2 + 1, weight}); // v_even
		}
	}

	cout << dijkstra(0*2 + 1, (c-1)*2 + 1, graph2) << "\n";
	
	return 0; 
}
