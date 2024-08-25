// https://cses.fi/problemset/task/1679
// topic: Topological sorting
// time: O(n + m)
// space: O(n)
#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define DEBUG(x) cout << #x << ">>> " << x << endl;

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    vector<int> in_degree(n);
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        graph[u].push_back(v);
        in_degree[v]++;
    }

    vector<int> top_sort;
    queue<int> qu;
    for(int i = 0; i < n; ++i) {
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

    if(top_sort.size() == n) {
        for(int i = 0; i < n; ++i) {
            if (i != 0)
                cout << " ";
            cout << top_sort[i] + 1;
        }
        cout << "\n";
    }
    else {
       cout << "IMPOSSIBLE\n"; 
    }
    
    return 0;
}

