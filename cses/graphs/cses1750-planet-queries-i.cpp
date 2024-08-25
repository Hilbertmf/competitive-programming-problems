// topic: binary lifting
// time: O(n * log(q))
// space: O(n * log(1e9))
#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
int getLog(int n) {
    int LOG = 1;
    while ((1 << LOG) <= n) {
        LOG++;
    }
    return LOG;
}
 
int goUp(vector<vector<int>>& up, int node, int k) {
    int LOG = up[0].size();
    for (int i = LOG - 1; i >= 0; --i) {
        if ((1 << i) <= k) {
            k -= (1 << i);
            node = up[node][i];
            if (node <= -1) break;
        }
    }
    return node;
}
 
int main() {
    FASTIO;
    int n, q, t;
    cin >> n >> q;
    int parent[n];
    fill(parent, parent + n, -1);
    for (int i = 0; i < n; ++i) {
        cin >> t;
        t--;
        parent[i] = t;
    }
 
    int LOG = getLog(1e9);
    vector<vector<int>> up(n, vector<int>(LOG, -1));
 
    for (int i = 0; i < n; ++i) {
        up[i][0] = parent[i];
    }
 
    for (int j = 1; j < LOG; ++j) {
        for (int i = 0; i < n; ++i) {
            if (up[i][j - 1] >= 0) {
                up[i][j] = up[ up[i][j - 1] ][j - 1];
                if (up[i][j] <= -1) break;
            }
            else break;
        }
    }
 
    while (q--) {
        int start, k;
        cin >> start >> k;
        start--;
        start = goUp(up, start, k);
        cout << (start == -1 ? -1 : start + 1) << "\n";
    }
 
    return 0;
}
