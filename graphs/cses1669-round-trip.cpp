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

void dfs(int node, vector<list<int>>& graph, vector<int>& visited, vector<int>& parents,
int& startCycle, int& endCycle, int depth) {
    visited[node] = 1; // visiting

    for(auto &neighbor : graph[node]) {
        if(visited[neighbor] == 2 || neighbor == parents[node]) continue;
        if(visited[neighbor] == 1 && depth >= 2) { // cycle
            startCycle = neighbor;
            endCycle = node;
        }
        else {
            parents[neighbor] = node;
            dfs(neighbor, graph, visited, parents, startCycle, endCycle, depth + 1);
        }
    }

    visited[node] = 2; // visited
}

string getCycle(vector<list<int>>& graph) {
    string cycle;
    vector<int> visited(graph.size());
    int endCycle = -1, startCycle = -1;
    vector<int> parents(graph.size(), -1);

    for(int v = 0; v < graph.size(); ++v) {
        if(visited[v] == 0) {
            dfs(v, graph, visited, parents, startCycle, endCycle, 0);
        }
        if(startCycle != -1) {
            parents[startCycle] = -1;
            break;
        }
    }

    int vertex = endCycle;
    while(endCycle != -1 && vertex != -1) {

        cycle += to_string(vertex + 1);
        cycle += " ";
        vertex = parents[vertex];
    }
    
    if(!cycle.empty())
        cycle += to_string(endCycle + 1);

    return cycle;
}

int main() { 
    FASTIO;
    int n, m;
    cin >> n >> m;
    vector<list<int>> graph(n);
    for(int i = 0; i < m; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        v1--; v2--;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    string path = getCycle(graph);
    

    if(!path.empty()) {
        int numSpaces = count(path.begin(), path.end(), ' ');
        cout << numSpaces + 1 << "\n";
        cout << path << "\n";
    }
    else {
        cout << "IMPOSSIBLE" << "\n";
    }
    
    return 0; 
}
