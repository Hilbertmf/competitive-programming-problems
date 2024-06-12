#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

class UnionFind {

public:

    vector<int> parents;
    vector<int> group_sizes;
    int num_elems;
    int num_groups;

    UnionFind(int size) {
        if (size <= 0) return;

        num_elems = size;
        num_groups = size;
        parents.resize(size);
        group_sizes.resize(size);

        for(int i = 0; i < size; ++i) {
            parents[i] = i;
            group_sizes[i] = 1;
        }
    }

    int find(int node) {

        int root = node;
        while (root != parents[root]) {
            root = parents[root];
        }

        // path compression
        while (node != parents[node]) {
            int next = parents[node];
            parents[node] = root;
            node = next;
        }

        return root;
    }

    bool isConnected(int node1, int node2) {
        return find(node1) == find(node2);
    }

    int groupSize(int node) {
        return group_sizes[find(node)];
    }

    int size() {
        return num_elems;
    }

    int numComponents() {
        return num_groups;
    }

    void join(int node1, int node2) {

        int root1 = find(node1);
        int root2 = find(node2);
        
        if (root1 == root2)
            return;

        if (group_sizes[root1] > group_sizes[root2]) {
            group_sizes[root1] += group_sizes[root2];
            parents[root2] = root1;
        }
        else {
            group_sizes[root2] += group_sizes[root1];
            parents[root1] = root2;
        }

        num_groups--;
    }
};

void dfs(int node, vector<vector<int>>& graph, vector<bool>& vis,
int& edge_count) {

    edge_count += graph[node].size();
    for(auto &adj : graph[node]) {
        if (!vis[adj]) {
            vis[adj] = true;
            dfs(adj, graph, vis, edge_count);
        }
    }
}

int complete_graph(int nodes) {
    return (nodes * (nodes - 1)) / 2;
}

int32_t main() {
    FASTIO;

    int users, num_edges;
    cin >> users >> num_edges;
    vector<vector<int>> graph(users);
    UnionFind dsu(users);

    for(int i = 0; i < num_edges; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        v1--;
        v2--;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
        dsu.join(v1, v2);
    }

    vector<bool> vis(users);
    map<int, int> edge_counts;
    for(int i = 0; i < users; ++i) {
        if (!vis[i]) {
            vis[i] = true;
            int edge_count = 0;
            dfs(i, graph, vis, edge_count);
            edge_counts[dsu.find(i)] = edge_count / 2;
        }
    }

    int ans = 0;
    for(auto &[k, v] : edge_counts) {
        ans += complete_graph(dsu.groupSize(k)) - v;
    }
    cout << ans << "\n";

    return 0;
}