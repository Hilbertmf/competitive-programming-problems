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


void dfs(int v, int end, vector<bool>& visited, vector<int>& parents,
vector<vector<pair<int, int>>>& graph, pair<int, int> removed) {

    for(auto &[adj, w] : graph[v]) {
        if(adj == parents[v] || visited[adj] ||
        (v == removed.first && adj == removed.second) ||
        (v == removed.second && adj == removed.first))
            continue;
        
        visited[adj] = true;
        parents[adj] = v;
        if(v == end)
            return;

        dfs(adj, end, visited, parents, graph, removed);
    }
}

vector<int> constructCycle(int first, int second,
vector<vector<pair<int, int>>>& graph) {
    
    int n = graph.size();
    vector<bool> visited(n);
    vector<int> parents(n, -1);

    parents[first] = -1;

    // we know first and second are in a cycle
    // remove the edge (first, second) from the graph
    // then try to reach second from first
    pair<int, int> removed = {first, second};
    dfs(first, second, visited, parents, graph, removed);
    vector<int> cycle;

    int v = second;

    while (v != first) {
        cycle.push_back(v);
        v = parents[v];
    }
    cycle.push_back(first);

    return cycle;
}

int32_t main() {
    FASTIO;
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        UnionFind dsu(n);
        vector<vector<int>> edges(m);
        vector<vector<pair<int, int>>> graph(n);
        vector<int> min_edge_cycle {INF, INF, INF};

        for(int i = 0; i < m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            u--;
            v--;
            edges[i] = {w, v, u};
        }

        sort(edges.rbegin(), edges.rend());

        for(int i = 0; i < m; ++i) {
            int w = edges[i][0], u = edges[i][1], v = edges[i][2];

            // if already connected, there's a cycle
            bool hasCycle = dsu.isConnected(u, v);
            dsu.join(u, v);
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});

            if (hasCycle && min_edge_cycle[0] > w) {
                min_edge_cycle = {w, u, v};
            }
        }

        int first = min_edge_cycle[1];
        int second = min_edge_cycle[2];

        vector<int> cycle = constructCycle(first, second, graph);

        cout << min_edge_cycle[0] << " " << cycle.size() << "\n";
        for(auto &v : cycle) {
            cout << v + 1 << " ";
        }
        cout << "\n";
    }    

    return 0;
}
