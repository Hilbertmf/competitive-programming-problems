// O(2^m + C(n,m)*(V+E))
// https://atcoder.jp/contests/abc328/tasks/abc328_e
// accepted
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
#define MAX 100 

bool hasCycleHelper(int vertex, vector<vector<vector<int>>>& graph, vector<vector<int>>& edges,
vector<bool>& vis, int color, vector<int>& colors) {
    bool res = false;

    for(auto &vec : graph[vertex]) {
        int adj = vec[0], edge_id = vec[2];
        if(edges[edge_id][3] == 0) continue;
        if(color == colors[adj])
            return true;
        if(vis[adj]) continue;

        colors[adj] = color ^ 1;
        vis[adj] = true;
        res |= hasCycleHelper(adj, graph, edges, vis, color ^ 1, colors);
        if(res == true) return res;
    }

    return res;
}

bool hasCycle(vector<vector<vector<int>>>& graph, vector<vector<int>>& edges) {
    vector<bool> vis(graph.size());
    vis[1] = true;
    vector<int> colors(graph.size(), -1);
    colors[1] = 1;
    return hasCycleHelper(1, graph, edges, vis, 1, colors);
}

void traverse(int vertex, vector<vector<vector<int>>>& graph, vector<vector<int>>& edges,
vector<bool>& vis) {
    for(auto &vec : graph[vertex]) {
        int adj = vec[0], edge_id = vec[2];
        if(vis[adj]) continue;
        if(edges[edge_id][3] == 0) continue;// edge not valid

        vis[adj] = true;
        traverse(adj, graph, edges, vis);
    }
}

bool isConnected(vector<vector<vector<int>>>& graph, vector<vector<int>>& edges) {
    bool result = true;
    
    vector<bool> vis(graph.size());
    vis[1] = true;
    traverse(1, graph, edges, vis);

    // check
    for(int i = 1; i < vis.size(); ++i) {
        if(!vis[i]) {
            result = false;
            break;
        }
    }
    return result;
}

int explicitEnumeration(int num_edges, vector<vector<vector<int>>>& graph, vector<vector<int>>& edges, int mod) {
    int bit = (1 << num_edges) - 1; // 2 ^ m - 1
    int n = graph.size() - 1;
    int sum = LONGINF;
    int aux = 0;

    while(bit >= 1) {

        int bits_on = __builtin_popcountll(bit);

        if(bits_on == n - 1) {

            int curr_bit = bit;
            int count = 0;
            int curr_sum = 0;

            for(int i = 0; i < edges.size(); ++i) {
                edges[i][3] = 0;
            }

            while(curr_bit >= 1) {
                if(curr_bit & 1) {
                    edges[count][3] = 1; // valid edge
                    curr_sum += edges[count][2] % mod;
                    curr_sum %= mod;
                }

                curr_bit >>= 1;
                count++;
            }

            if(curr_sum < sum) {

                vector<bool> vis(graph.size());
                vis[1] = true;
                bool is_connected = isConnected(graph, edges);
                bool has_cycle = is_connected && hasCycle(graph, edges);

                if(is_connected && !has_cycle) {
                    sum = min(sum, curr_sum);
                    
                }
            }
        }

        bit--;
    }

    return sum % mod;
}

int32_t main() { 
    FASTIO;

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<vector<int>>> graph(n + 1);
    vector<vector<int>> edges;

    for(int i = 0; i < m; ++i) {
        int u, v, w;
        int edge_id = i;
        cin >> u >> v >> w;
        w %= k;
        edges.push_back({u, v, w, 1}); // u, v, weight, is_valid_edge
        graph[u].push_back({v, w, edge_id}); // adj, weight and if its active
        graph[v].push_back({u, w, edge_id});
    }

    cout << explicitEnumeration(m, graph, edges, k) << "\n";

    return 0; 
}
