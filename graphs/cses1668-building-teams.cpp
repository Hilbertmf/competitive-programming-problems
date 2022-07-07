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

void colorGraph(int vertex, vector<list<int>>& graph,
vector<bool>& visited, int color, vector<int>& colors) {
    colors[vertex] = color;
    color ^= 1;

    for(auto &neighbor : graph[vertex]) {
        if(visited[neighbor]) continue;
        visited[neighbor] = true;
        colorGraph(neighbor, graph, visited, color, colors);
    }
}

int main() { 
    FASTIO;
    int n, m;
    cin >> n >> m;
    vector<list<int>> graph(n);
    vector<bool> visited(n);
    for(int i = 0; i < m; ++i) {
        int n1, n2;
        cin >> n1 >> n2;
        n1--;
        n2--;
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }

    bool possible = true;
    vector<int> colors(n, -1);
    
    for(int v = 0; v < n; ++v) {
        if(!visited[v])	{
            visited[v] = true;
            colorGraph(v, graph, visited, 1, colors);
        }
    }

    for(int v = 0; v < n && possible; ++v) {
        for(auto &neighbor : graph[v]) {
            if(colors[v] == colors[neighbor]) {
                possible = false;
                break;
            }
        }
    }
    
    
    if(possible) {
        for(int v = 0; v < n; ++v) {
            cout << colors[v] + 1;
            if(v != n - 1)
                cout << " ";
        }
        cout << "\n";
    }
    else {
        cout << "IMPOSSIBLE" << "\n";
    }

    return 0; 
}
