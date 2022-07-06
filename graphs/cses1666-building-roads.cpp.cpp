#include <bits/stdc++.h> 
using namespace std; 
#define DEBUG(x) cout << #x << " >>>> " << x << endl 
#define MID(l, r) (l + (r - l) / 2) 
#define CEILDIVISION(x, y) ((x + y - 1) / y) 
#define INF (int)1e9 
#define LONGINF (long long)1e18 
#define MEM(arr, val) memset(arr, (val), sizeof(arr)) 
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
const int MOD = 1000000007; // 10^9 - 7 

void dfs(int node, vector<list<int>>& graph, vector<bool>& visited) {

    for(auto &neighbor : graph[node]) {
        if(!visited[neighbor]) {
            visited[neighbor] = true;
            dfs(neighbor, graph, visited);
        }
    }
}

int main() { 
    FASTIO;
    int nodes, edges;
    cin >> nodes >> edges;
    vector<list<int>> graph(nodes);
    vector<bool> visited(nodes);
    vector<pair<int, int>> newRoads;
    int numIslands = 0;

    for(int i = 0; i < edges; ++i) {
        int n1, n2;
        cin >> n1 >> n2;
        --n1;
        --n2;
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }

    for(int n = 0; n < nodes; ++n) {
        if(!visited[n]) {
            visited[n] = true;
            numIslands++;
            dfs(n, graph, visited);

            if(numIslands > 1)
                newRoads.push_back({1, n + 1});
        }
    }

    cout << numIslands - 1 << "\n";
    for(auto &road : newRoads) {
        cout << road.first << " " << road.second << "\n";
    }
    
    return 0; 
}
