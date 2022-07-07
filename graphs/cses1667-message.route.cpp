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

int bfs(int start, int end, vector<list<int>>& graph, string& path) {
    vector<bool> visited(graph.size());
    queue<pair<int, int>> qu;
    qu.push({start, 1});
    visited[start] = true;
    vector<int> parents(graph.size());
    parents[start] = -1;
    int pathLength = -1;

    while (!qu.empty()) {
        int v = qu.front().first;
        int dist = qu.front().second;
        qu.pop();

        if(v == end) {
            pathLength = dist;
            break;
        }
        
        for(auto &neighbor : graph[v]) {
            if(visited[neighbor]) continue;
            visited[neighbor] = true;
            qu.push({neighbor, dist + 1});
            parents[neighbor] = v;
        }
    }

    if(pathLength == -1) {
        return -1;
    }
    else {
        // populate path
        int vertex = end;
        while(vertex != start) {
            if(path.size() > 0)
                path += " ";
            string tmp = to_string(vertex + 1);
            reverse(tmp.begin(), tmp.end());
            path += tmp;
            vertex = parents[vertex];
        }
        path += " ";
        string tmp = to_string(vertex + 1);
        reverse(tmp.begin(), tmp.end());
        path += tmp;
        reverse(path.begin(), path.end());
        return pathLength;		
    }
}

int main() { 
    FASTIO;
    int vertices, edges;
    cin >> vertices >> edges;
    vector<list<int>> graph(vertices);

    for(int i = 0; i < edges; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        v1--;
        v2--;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    string path;
    int dist = bfs(0, vertices - 1, graph, path);

    if(dist != -1) {
        cout << dist << "\n";
        cout << path << "\n";
    }
    else {
        cout << "IMPOSSIBLE" << "\n";
    }
    
    return 0; 
}
