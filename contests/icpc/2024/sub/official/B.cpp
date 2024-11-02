// AC
// https://codeforces.com/gym/105327/problem/B
#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
int MAXN = 1e6;

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
        if (node == parents[node]) return node;
        return parents[node] = find(parents[node]);
    }
    bool isConnected(int node1, int node2) {
        return find(node1) == find(node2);
    }
    void join(int node1, int node2) {
        int root1 = find(node1), root2 = find(node2);
        if (root1 == root2) return;
        if (group_sizes[root2] > group_sizes[root1])
            swap(root2, root1);
        group_sizes[root1] += group_sizes[root2];
        parents[root2] = root1;
        num_groups--;
    }
};

int getMovieIdx(int movie) {
    return movie + MAXN;
}

void dfs(int u, unordered_map<int, vector<int>>& graph,
unordered_set<int>& vis, unordered_map<int, int>& par,
unordered_map<int, int>& depth, int d) {
    vis.insert(u);
    depth[u] = d;

    for(auto &v : graph[u]) {
        if (vis.find(v) != vis.end()) continue;
        par[v] = u;
        dfs(v, graph, vis, par, depth, d + 1);
    }
}

int32_t main() {
    FASTIO;

    int n, m;
    cin >> n >> m;
    unordered_map<int, vector<int>> graph;
    UnionFind dsu(n + m + MAXN + 1);
    unordered_map<int, int> par;
    unordered_map<int, int> depth;

    for(int movie = 1; movie <= n; ++movie) {
        int num_actors;
        cin >> num_actors;
        vector<int> actors(num_actors);
        for(int a = 0; a < num_actors; ++a) {
            cin >> actors[a];
            graph[actors[a]].push_back(getMovieIdx(movie));
            dsu.join(actors[a], getMovieIdx(movie));
        }
        graph[getMovieIdx(movie)] = actors;        
    }

    unordered_set<int> vis;
    for(int v = 1; v <= n; ++v) {        
        if (vis.find(getMovieIdx(v)) == vis.end()) {
            dfs(getMovieIdx(v), graph, vis, par, depth, 0);
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int start, dest;
        cin >> start >> dest;

        if(!dsu.isConnected(start, dest)) {
            cout << "-1\n";
            continue;
        }

        // take the lca
        int src = start, dst = dest;
        bool has_swap = false;
        if (depth[src] < depth[dst]) {
            swap(src, dst);
            has_swap = true;
        }

        vector<int> path1;
        vector<int> path2;
        while (depth[src] > depth[dst]) {
            path1.push_back(src);
            src = par[src];
        }
        while (src != dst) {
            path1.push_back(src);
            path2.push_back(dst);
            src = par[src];
            dst = par[dst];
        }
        path1.push_back(src);

        vector<int> path(path1.begin(), path1.end());
        for(int i = path2.size() - 1; i >= 0; --i)
            path.push_back(path2[i]);

        if (has_swap)
            reverse(path.begin(), path.end());

        cout << path.size() / 2 + 1 << "\n";
        for(int i = 0; i < path.size(); ++i) {
            cout << (path[i] < MAXN ? path[i] : path[i] - MAXN) << " ";
        }
        cout << "\n";
    }

    return 0;
}
