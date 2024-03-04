// https://usaco.org/index.php?page=viewproblem2&cpid=789
// time: O(nlogn + qlogq + alpha(n) * (n + q))
// space: O(n + q)
#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

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

bool cmp(vector<int>& v1, vector<int>& v2) {
    return v1[0] > v2[0];
}

int main() {
    FASTIO;

    freopen("mootube.in", "r", stdin);
	freopen("mootube.out", "w", stdout);

    int num_nodes, num_queries;
    cin >> num_nodes >> num_queries;
    vector<vector<int>> edges;
    edges.reserve(num_nodes - 1);
    for(int i = 0; i < num_nodes - 1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        edges.push_back({w, u, v});
    }

    vector<vector<int>> queries;
    queries.reserve(num_queries);
    for(int i = 0; i < num_queries; ++i) {
        int k, v;
        cin >> k >> v;
        queries.push_back({k, v - 1, i});
    }

    sort(edges.begin(), edges.end(), cmp);
    sort(queries.begin(), queries.end(), cmp);

    int idx = 0;
    UnionFind dsu(num_nodes);
    vector<int> ans(num_queries);
    for(int i = 0; i < num_queries; ++i) {
        int k = queries[i][0];
        int v = queries[i][1];
        int pos = queries[i][2];

        while (idx < edges.size() && edges[idx][0] >= k) {
            dsu.join(edges[idx][1], edges[idx][2]);
            idx++;
        }

        ans[pos] = dsu.groupSize(v) - 1;
    }

    for(int num : ans) {
        cout << num << "\n";
    }

    return 0;
}
