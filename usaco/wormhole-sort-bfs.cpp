// https://usaco.org/index.php?page=viewproblem2&cpid=992
// time: O(V*log(E)), for V,E <= 1000: O(V * V*log(E))
// space: O(V + E)
#include <bits/stdc++.h>
using namespace std;
#define INF numeric_limits<int>::max()
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int multisourceBfs(unordered_map<int, int>& displaced_nodes,
vector<vector<pair<int, int>>>& graph) {
    vector<bool> vis(graph.size());
    priority_queue<pair<int, int>, vector<pair<int, int>>> heap;
    unordered_set<int> destinations;
    for(auto &[node, location] : displaced_nodes) {
        heap.push({INF, node});
        destinations.insert(location);
    }
    
    int min_edge = INF;
    int reached_dsts = 0;
    while (!heap.empty()) {
        int edge = heap.top().first;
        int v = heap.top().second;
        heap.pop();

        if (vis[v]) continue;
        if (edge != INF)
            vis[v] = true;
        min_edge = min(min_edge, edge);
        
        if (edge != INF &&
        destinations.find(v) != destinations.end())
            reached_dsts++;
        if (reached_dsts == destinations.size())
            return min_edge;
        for(auto &[adj, w] : graph[v]) {
            if (!vis[adj])
                heap.push({w, adj});
        }
    }

    return -1;
}

int bfs(int src, int dst, vector<vector<pair<int, int>>>& graph) {
    vector<bool> vis(graph.size());
    priority_queue<pair<int, int>, vector<pair<int, int>>> heap;
    heap.push({INF, src});
    int min_edge = INF;
    while (!heap.empty()) {
        int edge = heap.top().first;
        int v = heap.top().second;
        heap.pop();

        if (vis[v]) continue;
        vis[v] = true;
        min_edge = min(min_edge, edge);
        if (v == dst) return min_edge;
        for(auto &[adj, w] : graph[v]) {
            if (!vis[adj])
                heap.push({w, adj});
        }
    }

    return -1;
}

int main() {
    FASTIO;
    freopen("wormsort.in", "r", stdin);
	freopen("wormsort.out", "w", stdout);

    int num_nodes, num_edges;
    cin >> num_nodes >> num_edges;

    unordered_map<int, int> displaced_cows;
    for(int i = 0; i < num_nodes; ++i) {
        int location;
        cin >> location;
        if (location - 1 != i) {
            displaced_cows[i] = location - 1;
        }
    }

    vector<vector<pair<int, int>>> graph(num_nodes);
    for(int i = 0; i < num_edges; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

        
    int min_edge = INF;

    if(num_nodes > 1000 || num_edges > 1000) {
        min_edge = multisourceBfs(displaced_cows, graph);
    }
    else {
        for(int i = 0; i < num_nodes; ++i) {
            if (displaced_cows.find(i) == displaced_cows.end())
                continue;
            min_edge = min(min_edge, bfs(i, displaced_cows[i], graph));
        }
    }

    if(min_edge == INF) {
        cout << "-1\n";
    }
    else {
        cout << min_edge << "\n";
    }

    return 0;
}
