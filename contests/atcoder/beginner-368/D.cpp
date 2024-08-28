// https://atcoder.jp/contests/abc368/tasks/abc368_d
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

unordered_set<int> wanted;

void getDepth(int node, int parent,
vector<int>& par, vector<vector<int>>& graph,
vector<int>& depth, int d) {
    par[node] = parent;
    depth[node] = d;
    for(auto &adj : graph[node]) {
        if (adj == parent) continue;
        getDepth(adj, node, par, graph, depth, d + 1);
    }
}

int getLOG(int depth) {
    int LOG = 1;
    while ((1 << LOG) <= depth) LOG++;
    return LOG;
}

int goUp(int& node, int steps, vector<vector<int>>& up, int LOG) {
    for(int i = 0; i < LOG; ++i, steps >>= 1) {
        if (steps & 1)
            node = up[node][i];
    }
    return node;
}

int lca(int a, int b, vector<vector<int>>& up, int LOG, vector<int>& depth) {
    if (depth[a] < depth[b])
        swap(a, b);

    int diff_depth = depth[a] - depth[b];
    goUp(a, diff_depth, up, LOG);
    
    if (a == b) return a;

    for (int i = LOG - 1; i >= 0; --i) {
        if (up[a][i] != up[b][i]) {
            a = up[a][i];
            b = up[b][i];
        }
    }
    return up[a][0];
}

void binaryLifting(vector<int>& par, int& LOG, vector<int>& depth,
vector<vector<int>>& up, vector<vector<int>>& graph) {
    int n = par.size();
    // choose 0 as the root
    int root = 0;
    getDepth(root, root, par, graph, depth, 0);
    LOG = getLOG(n);
    up = vector<vector<int>>(n, vector<int>(LOG));

    for (int i = 0; i < n; ++i)
        up[i][0] = par[i];
    for (int j = 1; j < LOG; ++j) {
        for (int i = 1; i < n; ++i) {
            up[i][j] = up[ up[i][j - 1] ][j - 1];
        }
    }
}

int solve_via_lca(int n, vector<vector<int>>& graph) {
    vector<int> depth(n);
    vector<vector<int>> up;
    int LOG;
    vector<int> par(n);
    binaryLifting(par, LOG, depth, up, graph);    
    int LCA = *wanted.begin();
    for(int cur : wanted) {
        LCA = lca(LCA, cur, up, LOG, depth);   
    }    
    unordered_set<int> vis;
    for(int cur : wanted) {
        while (cur != LCA && vis.find(cur) == vis.end()) {
            vis.insert(cur);
            cur = par[cur];
        }
        vis.insert(cur);
    }
    
    vis.insert(LCA);
    return vis.size();
}

vector<char> hasWantedInSubtree;

bool precompute(int node, int par, vector<vector<int>>& graph) {

    bool hasWanted = wanted.find(node) != wanted.end();

    for(auto &adj : graph[node]) {
        if (adj == par) continue;
        hasWanted |= precompute(adj, node, graph);
    }
    
    return hasWantedInSubtree[node] = hasWanted;
}

void dfs(int node, int par, vector<vector<int>>& graph,
int& count) {

    count++;
    for(auto &adj : graph[node]) {
        if (adj == par) continue;
        if (hasWantedInSubtree[adj])
            dfs(adj, node, graph, count);
    }
}

int solve_via_dfs(int n, vector<vector<int>> graph) {
    hasWantedInSubtree.resize(n, false);
    int root = *wanted.begin();
    precompute(root, -1, graph);
    int count = 0;
    dfs(root, -1, graph, count);
    return count;
}

int main() {
    FASTIO;
    int n, k, a, b;
    cin >> n >> k;
    vector<vector<int>> graph(n);

    for(int i = 0; i < n - 1; ++i) {
        cin >> a >> b;
        --a; --b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i = 0; i < k; ++i) {
        cin >> a;
        wanted.insert(--a);
    }

    cout << solve_via_lca(n, graph) << "\n";
    // cout << solve_via_dfs(n, graph) << "\n";

    return 0;
}