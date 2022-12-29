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

int populateDepths(int node, vector<vector<pair<int, int>>>& graph, vector<bool>& visited,
int depth) {
    int maxDepth = depth;
    for(auto &[neighborDepth, neighbor] : graph[node]) {
        if(!visited[neighbor]) {
            visited[neighbor] = true;
            neighborDepth = max(neighborDepth,
            populateDepths(neighbor, graph, visited, depth + 1));
            maxDepth = max(maxDepth, neighborDepth);
        }
    }
    return maxDepth;
}

void dfs(int node, vector<vector<pair<int, int>>>& graph, vector<bool>& visited,
unordered_map<int, int> leaves, int points) {
    int count = 0;
    if(leaves.find(node) != leaves.end())
        leaves[node] = points;

    for(auto &[neighborDepth, neighbor] : graph[node]) {
        if(!visited[neighbor]) {
            visited[neighbor] = true;
            count++;
            if(count > 1)
                points = 0;
            dfs(neighbor, graph, visited, leaves, points + 1);
        }
    }
}

int main() { 
    FASTIO;
    int n, k;
    cin >> n >> k;
    vector<int> parents(n + 1);
    vector<vector<pair<int, int>>> graph(n + 1);
    int parent = 1;

    for(int i = 2; i <= n; ++i) {
        cin >> parent;
        graph[parent].push_back({0, i});
    }

    unordered_map<int, int> leaves;
    for(int i = 1; i <= n; ++i) {
        if(graph[i].size() == 0)
            leaves.insert({i, 0});
    }

    vector<bool> visited(n + 1);
    visited[1] = true;

    cout << "test1" << endl;

    populateDepths(1, graph, visited, 1);

    for(int i = 1; i <= n; ++i) {
        DEBUG(i);
        for(auto &[d, n] : graph[i]) {
            DEBUG(n);
            DEBUG(d);
        }
        cout << "\n";
    }

    cout << "test2" << endl;
    fill(visited.begin(), visited.end(), false);
    // sort graph neighbors by depth
    for(int i = 1; i <= n; ++i) {
        sort(graph[i].begin(), graph[i].end());
    }        
    visited[1] = true;
    dfs(1, graph, visited, leaves, 1);
    cout << "test3" << endl;

    int ans = 0;
    vector<int> points;
    for(auto &[leaf, point] : leaves) {
        points.push_back(point);
    }
    sort(points.begin(), points.end(), greater<int>());

    for(int i = 0; i < k; ++i) {
        ans += points[i];
    }
    
    cout << ans << "\n";
    
    return 0; 
}
