// https://cses.fi/problemset/task/1678
#include <bits/stdc++.h> 
using namespace std; 
#define DEBUG(x) cout << #x << " >>>> " << x << endl 
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 

const int UNVISITED = 0;
const int VISITING = 1;
const int VISITED = 2;

bool dfs(int node, vector<vector<int>>& graph,
vector<int>& color, vector<int>& par,
int& start, int& end) {
    color[node] = VISITING;
    bool res = false;

    for(auto &adj : graph[node]) {
        if (color[adj] == VISITED) continue;
        if (color[adj] == VISITING) {
            start = node;
            end = adj;
            return true;
        }
        par[adj] = node;
        res |= dfs(adj, graph, color, par, start, end);
        if (res) break;
    }

    color[node] = VISITED;
    return res;
}

vector<int> constructCycle(int start, int end,
vector<int>& par) {
    vector<int> cycle;
    cycle.push_back(end);
    while (start != end) {
        cycle.push_back(start);
        start = par[start];
    }
    cycle.push_back(end);
    reverse(cycle.begin(), cycle.end());
    return cycle;
}

bool hasCycle(vector<vector<int>>& graph, int n,
vector<int>& cycle) {
    vector<int> color(n);
    vector<int> par(n, -1);
    int start = -1, end = -1;
    bool found_cycle = false;

    for(int i = 0; i < n && !found_cycle; ++i) {
        par[i] = -1;
        if (color[i] == UNVISITED &&
            dfs(i, graph, color, par, start, end)) {
            found_cycle = true;
        }
    }

    if (found_cycle) {
        cycle = constructCycle(start, end, par);
    }
    
    return found_cycle;
}

int main() {

    int n, m, a, b;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    for(int i = 0; i < m; ++i) {
        cin >> a >> b;
        --a; --b;
        graph[a].push_back(b);
    }

    vector<int> cycle;
    if (hasCycle(graph, n, cycle)) {
        cout << cycle.size() << "\n";
        for(int i = 0; i < cycle.size(); ++i) {
            cout << cycle[i] + 1 << " ";
        }
        cout << "\n";
    }
    else {
        cout << "IMPOSSIBLE\n";
    }

    return 0;
}
