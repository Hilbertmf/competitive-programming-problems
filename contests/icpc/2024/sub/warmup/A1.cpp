#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cassert>

#define FASTIO ios::sync_with_stdio(false); cin.tie(nullptr);

using namespace std;

const int INF = INT_MAX;
const int MAXN = 300;

void floydWarshall(int n, vector<vector<int>>& dist) {
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> dist(n, vector<int>(n, INF));
    vector<vector<pair<int, int>>> graph(n);
    vector<tuple<int, int, int>> edges;

    for (int i = 0; i < n; ++i) {
        dist[i][i] = 0; // Distance to self is zero
    }

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v; // Convert to 0-based index
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
        dist[u][v] = w;
        dist[v][u] = w;
        edges.push_back({u, v, w});
    }

    // Step 1: Compute all-pairs shortest paths using Floyd-Warshall
    floydWarshall(n, dist);

    // Step 2: For each edge, calculate the shortest path excluding that edge
    for (const auto& edge : edges) {
        int u, v, w;
        tie(u, v, w) = edge;

        // Temporarily remove edge (u, v) by setting distance to INF
        int original_distance = dist[u][v];
        dist[u][v] = INF;
        dist[v][u] = INF;

        int min_distance = INF;

        // Recalculate shortest path from u to v excluding the edge (u, v)
        for (int k = 0; k < n; ++k) {
            if (k != u && k != v) {
                if (dist[u][k] < INF && dist[k][v] < INF) {
                    min_distance = min(min_distance, dist[u][k] + dist[k][v]);
                }
            }
        }

        // Output the result
        cout << "Shortest path between " << u + 1 << " and " << v + 1 
             << " excluding direct edge: " << (min_distance == INF ? -1 : min_distance) << '\n';

        // Restore the original distance
        dist[u][v] = original_distance;
        dist[v][u] = original_distance;
    }

    return 0;
}



class Solution {
public:
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        
    }
};