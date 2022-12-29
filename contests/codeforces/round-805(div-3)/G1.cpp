// wrong answer
// https://codeforces.com/contest/1702/problem/G1
#include <bits/stdc++.h> 
using namespace std; 
#define DEBUG(x) cout << #x << " >>>> " << x << endl 
#define MID(l, r) (l + (r - l) / 2) 
#define CEILDIVISION(x, y) ((x + y - 1) / y) 
#define INF (long long)1e9 
#define LONGINF (long long)1e18 
#define MEM(arr, val) memset(arr, (val), sizeof(arr)) 
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
const long long MOD = 1000000007; // 10^9 - 7 

struct state{
    int node;
    long long dist;
};

void multisourceBfs(unordered_set<int>& origins, vector<list<int>>& graph,
vector<long long>& dists) {
    vector<bool> visited(graph.size());
    queue<state> qu;
    for(auto &origin : origins) {
        qu.push((state){origin, 0});
        dists[origin] = 0;
        visited[origin] = true;
    }

    while(!qu.empty()) {
        int node = qu.front().node;
        long long dist = qu.front().dist;
        qu.pop();

        for(auto &neighbor : graph[node]) {
            if(visited[neighbor]) continue;
            visited[neighbor] = true;
            dists[neighbor] = min(dists[neighbor], dists[node] + 1);
            qu.push((state){neighbor, dists[neighbor]});
        }
    }

}

void traversePath(int start, int end, vector<list<int>>& graph, unordered_set<int>& st) {
    vector<bool> visited(graph.size());
    vector<int> parents(graph.size());
    queue<int> qu;
    qu.push(start);
    visited[start] = true;
    parents[start] = -1;

    while(!qu.empty()) {
        int node = qu.front();
        qu.pop();

        
        for(auto &neighbor : graph[node]) {
            if(visited[neighbor]) continue;
            visited[neighbor] = true;
            qu.push(neighbor);
            parents[neighbor] = node;
        }
    }

    string path;
    int node = end;
    while(node != -1) {
        if(st.find(node) != st.end()) {
            st.erase(st.find(node));
        }
        node = parents[node];
    }
    
    return;
}

int main() {

    int n;
    cin >> n;
    vector<list<int>> graph(n);
    for(int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    unordered_set<int> leaves;
    for(int v = 0; v < n; ++v) {
        if(graph[v].size() == 1) {
            leaves.insert(v);
        }
    }
    
    vector<long long> distToLeaves(n, LONGINF);
    multisourceBfs(leaves, graph, distToLeaves);
    

    int q;
    cin >> q;
    while (q--) {
        int k;
        cin >> k;
        unordered_set<int> st;
        st.reserve(k);
        int startNode = -1;
        int endNode = -1;
        for(int i = 0; i < k; ++i) {
            int num;
            cin >> num;
            num--;
            st.insert(num);
            if(startNode == -1)
                startNode = num;
            else if(leaves.find(num) != leaves.end() && leaves.find(startNode) == leaves.end())
                startNode = num;
            else if(distToLeaves[num] < distToLeaves[startNode])
                startNode = num;
        }

        if(k <= 2) {
            cout << "YES" << "\n";
            continue;
        }

        vector<long long> distToStart(n, LONGINF);
        unordered_set<int> tmpSet{startNode};
        multisourceBfs(tmpSet, graph, distToStart);

        for(auto &num : st) {
            if(endNode == -1 && num != startNode)
                endNode = num;
            else if(distToStart[endNode] < distToStart[num])
                endNode = num;
        }

        traversePath(startNode, endNode, graph, st);

        if(st.empty()) {
            cout << "YES" << "\n";
        }
        else {
            cout << "NO" << "\n";
        }

    }
    
    return 0;
}