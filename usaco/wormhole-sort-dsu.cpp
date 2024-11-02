// https://usaco.org/index.php?page=viewproblem2&cpid=992
// time: O(E*log(E) + E * alpha(V))
// space: O(V + E)
#include <bits/stdc++.h>
using namespace std;
#define INF numeric_limits<int>::max()
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

class UnionFind {

public:

    vector<int> parents;
    vector<int> group_sizes;
    int num_elems;
    int num_groups;
    unordered_set<int> elems_to_sort;
    vector<unordered_set<int>> elems_in_group;
    bool visited_all;

    UnionFind(int size, unordered_set<int> elems) {
        if (size <= 0) return;

        num_elems = size;
        num_groups = size;
        parents.resize(size);
        group_sizes.resize(size);
        elems_in_group.resize(size);
        elems_to_sort = elems;
        visited_all = elems.empty();

        for(int i = 0; i < size; ++i) {
            parents[i] = i;
            group_sizes[i] = 1;
            if (elems.find(i) != elems.end())
                elems_in_group[i].insert(i);
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

    bool visitedAll() {
        return visited_all;
    }

    void join(int node1, int node2) {

        int root1 = find(node1);
        int root2 = find(node2);
        
        if (root1 == root2)
            return;

        if (group_sizes[root1] > group_sizes[root2]) {
            parents[root2] = root1;
            for(int num : elems_in_group[root2]) {
                elems_in_group[root1].insert(num);
            }
            group_sizes[root1] = elems_in_group[root1].size();
            if (group_sizes[root1] >= elems_to_sort.size())
                visited_all = true;
        }
        else {
            parents[root1] = root2;
            for(int num : elems_in_group[root1]) {
                elems_in_group[root2].insert(num);
            }
            group_sizes[root2] = elems_in_group[root2].size();
            if (group_sizes[root2] >= elems_to_sort.size())
                visited_all = true;
        }

        num_groups--;
    }
};

bool cmp(vector<int>& v1, vector<int>& v2) {
    return v1[0] > v2[0];
}

int main() {
    FASTIO;
    freopen("wormsort.in", "r", stdin);
	freopen("wormsort.out", "w", stdout);

    int num_nodes, num_edges;
    cin >> num_nodes >> num_edges;

    unordered_map<int, int> displaced_cows;
    unordered_set<int> elems_to_sort;
    vector<vector<int>> edges;
    for(int i = 0; i < num_nodes; ++i) {
        int location;
        cin >> location;
        if (location - 1 != i) {
            displaced_cows[i] = location - 1;
            elems_to_sort.insert(i);
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
        edges.push_back({w, u, v});
        edges.push_back({w, v, u});
    }

    UnionFind dsu(num_nodes, elems_to_sort);
    sort(edges.begin(), edges.end(), cmp);
    
    int min_edge = INF;

    for(int i = 0; i < edges.size(); ++i) {
        if (dsu.visitedAll()) break;

        int curr_edge = edges[i][0];
        int u = edges[i][1];
        int v = edges[i][2];
        min_edge = min(min_edge, curr_edge);

        dsu.join(u, v);
    }

    if(min_edge == INF) {
        cout << "-1\n";
    }
    else {
        cout << min_edge << "\n";
    }

    return 0;
}
