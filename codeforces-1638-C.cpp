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

void traverse(int node, vector<list<int>>& graph, vector<bool>& visited, vector<int>& perm) {

    if(!visited[perm[node]]) {
        visited[perm[node]] = true;
        traverse(perm[node], graph, visited, perm);
    }
    
    for(auto &neighbor : graph[node]) {
        if(!visited[neighbor]) {
            visited[neighbor] = true;
            traverse(neighbor, graph, visited, perm);
        } 
    }
}

int main() { 
    FASTIO;
    int t;
    cin >> t;
    while (t--) {
        int len;
        cin >> len;
        vector<int> perm(len + 1);
        for(int i = 1; i <= len; ++i) cin >> perm[i];
        
        set<int> st;
        vector<list<int>> graph(len + 1);
        
        for(int i = 1; i <= len; ++i) {
            
            auto low = st.lower_bound(perm[i]);
            if(st.size() && low != st.end()) {
                graph[*low].push_back(i);
            }

            st.insert(perm[i]);
        }

        vector<bool> visited(graph.size());
        int numIslands = 0;
        for(int i = 1; i <= len; ++i) {
            if(!visited[i]) {
                visited[i] = true;
                numIslands++;
                traverse(i, graph, visited, perm);
            }
        }
        
        cout << numIslands << "\n";
    }
    
    return 0; 
}
