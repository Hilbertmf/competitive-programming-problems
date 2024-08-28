// Tarjan algorithm for SCC
// time: O(V + E)
// space: O(V)
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl


vector<char> vis;
vector<int> idx, low;
map<int, vector<int>> sccs;
vector<char> in_stack;
int counter = 0;

bool canReach(int node, int end, vector<char>& vis,
vector<vector<int>>& graph) {
    if (node == end) return true;
    vis[node] = true;

    for(auto &adj : graph[node]) {
        if (vis[adj]) continue;
        if (canReach(adj, end, vis, graph))
            return true;
    }
    return false;
}

void dfs(int v, vector<vector<int>>& graph,
stack<int>& invariant) {

    idx[v] = low[v] = counter++;
    invariant.push(v);
    in_stack[v] = true;
    vis[v] = true;

    for(auto &adj : graph[v]) {
        if (!vis[adj]) {
            dfs(adj, graph, invariant);
        }
        if (in_stack[adj])
            low[v] = min(low[v], low[adj]);
    }

    // we're at root of scc
    if (idx[v] == low[v]) {
        while (!invariant.empty()) {
            int u = invariant.top();
            in_stack[u] = false;
            sccs[v].push_back(u);
            invariant.pop();
            if (u == v) break;
        }
    }

}

int main() {

    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        graph[u].push_back(v);
    }
        
    vis = vector<char>(n);
    in_stack = vector<char>(n);
    idx = vector<int>(n);
    low = vector<int>(n, INT_MAX);
    for(int i = 0; i < n; ++i) {
        if (vis[i]) continue;
        stack<int> invariant;
        dfs(i, graph, invariant);
    }

    if(sccs.size() == 1) {
        cout << "YES\n";
    }
    else {
        // try the first two roots:
        int root1 = sccs.begin()->first;
        int root2 = next(sccs.begin())->first;

        fill(vis.begin(), vis.end(), false);
        cout << "NO\n";
        if (canReach(root1, root2, vis, graph))
            cout << root2 + 1 << " " << root1 + 1 << "\n";
        else
            cout << root1 + 1 << " " << root2 + 1 << "\n";
    }

    return 0;
}
