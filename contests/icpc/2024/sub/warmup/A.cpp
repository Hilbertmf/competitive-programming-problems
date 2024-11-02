#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

// topic: Shortest Paths: all shortest paths for all (i, j)
// time: O(V³)
// space: O(V² + E)
vector<vector<int>> dist1;
vector<vector<int>> dist2;

void floydWarshallSecondMin(int n, vector<vector<pair<int, int>>>& graph) {
    // Initialize dist1 and dist2 matrices
    dist1 = vector<vector<int>>(n, vector<int>(n, INF));
    dist2 = vector<vector<int>>(n, vector<int>(n, INF));

    for (int i = 0; i < n; ++i) {
        for (auto& edge : graph[i]) {
            int j = edge.first, w = edge.second;
            dist1[i][j] = min(dist1[i][j], w);
        }
        dist1[i][i] = 0; // Distance to self is 0
    }

    for (int mid = 0; mid < n; ++mid) {
        for (int from = 0; from < n; ++from) {
            for (int to = 0; to < n; ++to) {
                if (dist1[from][mid] != INF && dist1[mid][to] != INF) {
                    int newDist = dist1[from][mid] + dist1[mid][to];
                    if (newDist < dist1[from][to]) {
                        dist2[from][to] = dist1[from][to];
                        dist1[from][to] = newDist;
                    } else if (newDist > dist1[from][to] && newDist < dist2[from][to]) {
                        dist2[from][to] = newDist;
                    }
                }

                // else if (dist2[from][mid] != INF && dist1[mid][to] != INF) {
                //     int newSecondDist = dist2[from][mid] + dist1[mid][to];
                //     if (newSecondDist > dist1[from][to] && newSecondDist < dist2[from][to]) {
                //         dist2[from][to] = newSecondDist;
                //     }
                // }

                // else if (dist1[from][mid] != INF && dist2[mid][to] != INF) {
                //     int newSecondDist = dist1[from][mid] + dist2[mid][to];
                //     if (newSecondDist > dist1[from][to] && newSecondDist < dist2[from][to]) {
                //         dist2[from][to] = newSecondDist;
                //     }
                // }
            }
        }
    }
}

int32_t main() {
    FASTIO;

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n);
    vector<vector<int>> edges;
    for(int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
        edges.push_back({u, v, w});
    }

    for(auto &edge : edges) {
        //output answer
    }
    
    return 0;
}
