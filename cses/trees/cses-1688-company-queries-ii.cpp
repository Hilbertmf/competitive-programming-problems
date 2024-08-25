// https://cses.fi/problemset/task/1688
// topic: LCA via Binary lifting
// time: O(nlogn + q*logn)
// space: O(nlogn)
#include <bits/stdc++.h>
#define DEBUG(x) cout << #x << " >>>> " << x << endl 
using namespace std;

int dfs(int root, vector<vector<int>>& tree, int d,
vector<int>& depth) {
    depth[root] = d;
    int curr = d;
    for(auto &adj : tree[root]) {
        curr = max(curr, dfs(adj, tree, d + 1, depth));
    }
    return curr;
}

int getDepth(int root, vector<int>& par, vector<int>& depth) {
    int n = par.size();
    vector<vector<int>> tree(n);
    for(int i = 1; i < n; ++i) {
        tree[par[i]].push_back(i);
    }
    return dfs(root, tree, 0, depth);
}

int getLOG(int depth) {
    int LOG = 0;
    while ((1 << LOG) <= depth) {
        LOG++;
    }
    return LOG;
}


int goUp(int& node, int steps, vector<vector<int>>& anc, int LOG) {
    for(int i = LOG - 1; i >= 0; --i) {
        // if we can make that jump
        if ((1 << i) <= steps) {
            steps -= (1 << i);
            node = anc[node][i];
        }
    }
    return node;
}

int lca(int a, int b, vector<vector<int>>& anc, int LOG,
vector<int>& depth) {
    if (a == 0 || b == 0) return 0;

    // make depth equal:
    if (depth[a] < depth[b])
        swap(a, b);

    int diff_depth = depth[a] - depth[b];
    goUp(a, diff_depth, anc, LOG);
    
    if (a == b) return a;

    for(int i = LOG - 1; i >= 0; --i) {
        if (anc[a][i] != anc[b][i]) {
            a = anc[a][i];
            b = anc[b][i];
        }
    }

    return anc[a][0];
}

int main()  {

    int n, q;
    cin >> n >> q;
    vector<int> par(n);
    par[0] = 0;
    for(int i = 1; i < n; ++i) {
        int boss;
        cin >> boss;
        boss--;
        par[i] = boss;
    }

    vector<int> depth(n);
    int d = getDepth(0, par, depth);
    int LOG = getLOG(d);// + 1;
    vector<vector<int>> anc(n, vector<int>(LOG));

    for(int i = 0; i < n; ++i) {
        anc[i][0] = par[i];
    }

    for(int j = 1; j < LOG; ++j) {
        for(int i = 1; i < n; ++i) {
            anc[i][j] = anc[ anc[i][j - 1] ][j - 1];
        }
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        cout << lca(a, b, anc, LOG, depth) + 1 << "\n";
    }

    return 0;
}
