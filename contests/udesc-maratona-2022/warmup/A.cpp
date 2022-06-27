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

long long dfsOnComplement(int node, vector<set<int>>& graph, set<int>& unvisited) {
    unvisited.erase(unvisited.find(node));
    long long size = 1;
    int val = 0;
    for(auto it = unvisited.begin(); it != unvisited.end();
    it = unvisited.upper_bound(val)){//we use upperbound because erasing invalidates the iterator
        val = *it;

        // is neighbor on complement graph
        if(graph[node].find(*it) == graph[node].end()) {
            size += dfsOnComplement(*it, graph, unvisited);
        }
    }

    return size;
}

int main() { 
    FASTIO;
    int numComputers, numNonConnections, numQueries;

    cin >> numComputers >> numNonConnections >> numQueries;

    vector<set<int>> graph(numComputers + 1);
    set<int> unvisited;
    vector<long long> islandSizes;

    for(int i = 1; i <= numComputers; ++i) unvisited.insert(i);
    
    int v1, v2;

    for(int i = 0; i < numNonConnections; ++i) {
        cin >> v1 >> v2;
        graph[v1].insert(v2);
        graph[v2].insert(v1);
    }

    for(int i = 1; i <= numComputers; ++i) {
        if(unvisited.find(i) != unvisited.end()) {
            islandSizes.push_back(dfsOnComplement(i, graph, unvisited));
        }
    }

    sort(islandSizes.begin(), islandSizes.end(), greater<int>());


    for(int i = 1; i < islandSizes.size(); ++i) {
        islandSizes[i] += islandSizes[i - 1];
    }

    while(numQueries--) {
        int computers;
        cin >> computers;
        if(computers == 0)
            cout << 0 << "\n";
        else if(computers >= islandSizes.size())
            cout << islandSizes[islandSizes.size() - 1] << "\n";
        else
            cout << islandSizes[computers - 1] << "\n";

    }

    return 0;
}
