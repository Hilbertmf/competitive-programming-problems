// https://usaco.org/index.php?page=viewproblem2&cpid=646
// time: O(v * e * alpha(v))
// space: O(v)
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

int main() {

    freopen("closing.in", "r", stdin);
	freopen("closing.out", "w", stdout);

    int num_nodes, edges;
    cin >> num_nodes >> edges;
    UnionFind dsu(num_nodes);
    int u, v;
    vector<vector<int>> graph(num_nodes);

    for(int i = 0; i < edges; ++i) {
        cin >> u >> v;
        u--;
        v--;
        graph[v].push_back(u);
        graph[u].push_back(v);
    }


    vector<char> ans;
    ans.reserve(num_nodes);
    ans.push_back('y');

    vector<int> nodes(num_nodes);
    for(int i = 0; i < num_nodes; ++i) {
        int tmp;
        cin >> tmp;
        nodes[i] = tmp - 1;
    }
    reverse(nodes.begin(), nodes.end());

    unordered_set<int> added_nodes;
    for(int i = 0; i < num_nodes; ++i) {
        
        int curr = nodes[i];
        added_nodes.insert(curr);
        if (i == 0) continue;

        for(auto &adj : graph[curr]) {
            if (added_nodes.find(adj) != added_nodes.end())
                dsu.join(adj, curr);
        }

        if(dsu.groupSize(curr) == added_nodes.size()) {
            ans.push_back('y');
        }
        else {
            ans.push_back('n');
        }
    }

    reverse(ans.begin(), ans.end());
    for(char c : ans) {
        if(c == 'y') {
            cout << "YES" << "\n";
        }
        else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
