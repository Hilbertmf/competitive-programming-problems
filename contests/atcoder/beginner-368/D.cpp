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


    void dfs(int v, vector<int> graph[], vector<char>& vis) {
        vis[v] = true;
        for(auto &u : graph[v]) {
            if (vis[u]) continue;
            dfs(u, graph, vis);
        }
    }
    int countComponents(int n, vector<int> graph[]) {
        vector<char> vis(n, false);
        int comp = 0;
        for(int i = 0; i < n; ++i) {
            if (!vis[i]) {
                dfs(i, graph, vis);
                comp++;
            }
        }
        return comp;
    }

    int isBridge(int n, vector<int> graph[], int c, int d) {
        int comp = countComponents(n, graph);
        // remove edge
        graph[c].erase(find(graph[c].begin(), graph[c].end(), d));
        graph[d].erase(find(graph[d].begin(), graph[d].end(), c));

        int new_comp = countComponents(n, graph);
        return new_comp > comp;
    }



#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
        if (parents[node] == node) return node;
        return parents[node] = find(parents[node]);
    }
    int groupSize(int node) {
        return group_sizes[find(node)];
    }

    void join(int node1, int node2) {
        int root1 = find(node1);
        int root2 = find(node2);        
        if (root1 == root2)
            return;
        if (root2 > root1)
            swap(root1, root2);
        group_sizes[root1] += group_sizes[root2];
        parents[root2] = root1;
        num_groups--;
    }
    int numComponents() {
        return num_groups;
    }
};

class Solution {
public:    
    int removeStones(vector<vector<int>>& stones) {
        FASTIO;
        int n = stones.size();
        // normalize the data
        vector<int> rows_norm;
        vector<int> cols_norm;
        for(auto &stone : stones) {
           rows_norm.push_back(stone[0]);
           cols_norm.push_back(stone[1]);
        }
        sort(rows_norm.begin(), rows_norm.end());
        sort(cols_norm.begin(), cols_norm.end());
        rows_norm.erase(unique(rows_norm.begin(), rows_norm.end()), rows_norm.end());
        cols_norm.erase(unique(cols_norm.begin(), cols_norm.end()), cols_norm.end());
        unordered_map<int, int> tab_row;
        unordered_map<int, int> tab_col;
        for(int i = 0; i < max(rows_norm.size(), cols_norm.size()); ++i) {
            if (i < rows_norm.size())
                tab_row[rows_norm[i]] = i;
            if (i < cols_norm.size())
                tab_col[cols_norm[i]] = i;
        }
        int rows = rows_norm.size(), cols = cols_norm.size();        
        vector<vector<int>> norm_stones = stones;
        for(auto &stone : norm_stones) {
            stone = {tab_row[stone[0]], tab_col[stone[1]]};
        }

        UnionFind dsu(rows + cols + n);

        for(int i = 0; i < n; ++i) {
            int r = norm_stones[i][0];
            int c = norm_stones[i][1];
            dsu.join(r, rows + cols + i);
            dsu.join(rows + c, rows + cols + i);
        }

        cout << dsu.numComponents() << endl;
        return n - dsu.numComponents();
    }
};


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
        if (parents[node] == node) return node;
        return parents[node] = find(parents[node]);
    }
    int groupSize(int node) {
        return group_sizes[find(node)];
    }

    void join(int node1, int node2) {
        int root1 = find(node1);
        int root2 = find(node2);        
        if (root1 == root2)
            return;
        if (root2 > root1)
            swap(root1, root2);
        group_sizes[root1] += group_sizes[root2];
        parents[root2] = root1;
        num_groups--;
    }
    int numComponents() {
        return num_groups;
    }
};

class Solution {
public:
    map<pair<int, int>, int> tab;

    int rowColIdx(int r, int c, int rows, int cols) {
        return cols * r + c;
    }
    
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        // normalize the data
        set<int> rows_set;
        set<int> cols_set;
        for(auto &stone : stones) {
           rows_set.insert(stone[0]);
           cols_set.insert(stone[1]);
        }
        unordered_map<int, int> tab_row;
        unordered_map<int, int> tab_col;
        int count = 0;
        int rows = 0, cols = 0;
        for(int r : rows_set) {
            tab_row[r] = count;
            count++;
        }
        rows = count;
        count = 0;
        for(int c : cols_set) {
            tab_col[c] = count;
            count++;
        }
        cols = count;
        
        vector<vector<int>> norm_stones = stones;

        for(auto &stone : norm_stones) {
            stone = {tab_row[stone[0]], tab_col[stone[1]]};
        }

        UnionFind dsu(rows + cols + n);

        for(int i = 0; i < n; ++i) {
            int r = norm_stones[i][0];
            int c = norm_stones[i][1];
            dsu.join(r, rows + cols + i);
            dsu.join(rows + c, rows + cols + i);
        }

        cout << dsu.numComponents() << endl;
        return n - dsu.numComponents();
    }
};