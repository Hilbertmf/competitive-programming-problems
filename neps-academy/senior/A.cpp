#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl

/*
try to greedily do the operation instead

*/

void visit(int v, vector<vector<int>>& graph,
vector<char>& vis) {
    for(auto &adj : graph[v]) {
        if (vis[adj]) continue;
        vis[adj] = true;
        visit(adj, graph, vis);
    }
}

vector<int> topSort(vector<int>& in_degree,
vector<vector<int>>& graph) {
    vector<int> top_sort;
    queue<int> qu;
    for(int i = 0; i < in_degree.size(); ++i) {
        // has no parent
        if (in_degree[i] == 0)
            qu.push(i);
    }

    while (!qu.empty()) {
        int node = qu.front();
        qu.pop();

        top_sort.push_back(node);
        for(auto &adj : graph[node]) {
            in_degree[adj]--;
            if (in_degree[adj] == 0)
                qu.push(adj);
        }
    }
    
    return top_sort;
}

vector<bool> visited; // keeps track of which vertices are already visited

// runs depth first search starting at vertex v.
// each visited vertex is appended to the output vector when dfs leaves it.
void dfs(int v, vector<vector<int>> const& graph, vector<int> &output) {
    visited[v] = true;
    for (auto u : graph[v])
        if (!visited[u])
            dfs(u, graph, output);
    output.push_back(v);
}

// input: graph -- adjacency list of G
// output: components -- the strongy connected components in G
// output: condensed_graph -- adjacency list of G^SCC (by root vertices)
void strongy_connected_components(vector<vector<int>> const& graph,
                                  vector<vector<int>> &components,
                                  vector<vector<int>> &condensed_graph) {
    int n = graph.size();
    components.clear(), condensed_graph.clear();

    vector<int> order; // will be a sorted list of G's vertices by exit time

    visited.assign(n, false);

    // first series of depth first searches
    for (int i = 0; i < n; i++)
        if (!visited[i])
            dfs(i, graph, order);

    // create adjacency list of G^T
    vector<vector<int>> adj_rev(n);
    for (int v = 0; v < n; v++)
        for (int u : graph[v])
            adj_rev[u].push_back(v);

    visited.assign(n, false);
    reverse(order.begin(), order.end());

    vector<int> roots(n, 0); // gives the root vertex of a vertex's SCC

    // second series of depth first searches
    for (auto v : order)
        if (!visited[v]) {
            std::vector<int> component;
            dfs(v, adj_rev, component);
            sort(component.begin(), component.end());
            components.push_back(component);
            int root = component.front();
            for (auto u : component)
                roots[u] = root;
        }

    // add edges to condensation graph
    condensed_graph.assign(n, {});
    for (int v = 0; v < n; v++)
        for (auto u : graph[v])
            if (roots[v] != roots[u])
                condensed_graph[roots[v]].push_back(roots[u]);
}


int main() {
    int n, m;
    cin >> n >> m;
    set<pair<int, int>> edges;
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        if (u != v)
            edges.insert({u, v});
    }

    vector<set<int>> graph_set(n);
    vector<int> scc_id;
    for(auto &[u, v] : edges) {
        graph_set[u].insert(v);
    }

    vector<vector<int>> graph(n);
    for(int i = 0; i < n; ++i) {
        for(auto &adj : graph_set[i]) {
            graph[i].push_back(adj);
        }
    }

    vector<vector<int>> condensed_graph;
    vector<vector<int>> components;
    strongy_connected_components(graph, components, condensed_graph);

    vector<int> in_degree(n, 0);
    for (int i = 0; i < n; ++i) {
        for (int adj : condensed_graph[i]) {
            in_degree[adj]++;
        }
    }

    vector<int> nodes = topSort(in_degree, condensed_graph);
    vector<char> vis(n);
    int best = 0;

    for(int i = 0; i < n; ++i) {
        if (in_degree[i] == 0)
            best += condensed_graph[i].size();
    }

    cout << m - best << "\n";
    return 0;
}
