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

bool isLeaf(int node, vector<list<int>>& graph) {
    return graph[node].size() == 1 && node != 1;
}

bool isReachable(int node, vector<list<int>>& graph, vector<int>& depths,
vector<int>& distToFriend) {
    return depths[node] < distToFriend[node];
}

void populateDistToFriend1(int node, vector<list<int>>& graph, vector<bool>& visited, vector<int>& depths,
vector<int>& distToFriend, unordered_set<int>& friends, int depth) {
    depths[node] = depth;
    if(friends.find(node) != friends.end()) {
        distToFriend[node] = 0;
    }

    for(auto &neighbor : graph[node]) {
        if(!visited[neighbor]) {
            visited[neighbor] = true;
            populateDistToFriend1(neighbor, graph, visited, depths, distToFriend,
            friends, depth + 1);

            distToFriend[node] = min(distToFriend[node], distToFriend[neighbor] + 1);
        }
    }
}


void populateDistToFriend2(int node, int parent, vector<list<int>>& graph, vector<bool>& visited,
vector<int>& distToFriend) {
    if(node != 1) {
        distToFriend[node] = min(distToFriend[node], distToFriend[parent] + 1);
    }

    for(auto &neighbor : graph[node]) {
        if(!visited[neighbor]) {
            visited[neighbor] = true;
            populateDistToFriend2(neighbor, node, graph, visited, distToFriend);
        }
    }

    if(node != 1) {
        distToFriend[node] = min(distToFriend[node], distToFriend[parent] + 1);
    }

}

void countEssentialFriends(int node, vector<list<int>>& graph, vector<bool>& visited,
vector<int>& depths, vector<int>& distToFriend, bool& vladCanWin, int& essentialFriends) {
    // if we reach a leaf than vlad is always winning
    if(isLeaf(node, graph)) {
        vladCanWin = true;
        return;
    }
    
    for(auto &neighbor : graph[node]) {
        if(!visited[neighbor]) {
            visited[neighbor] = true;
            if(isReachable(neighbor, graph, depths, distToFriend))
                countEssentialFriends(neighbor, graph, visited, depths,distToFriend,
                vladCanWin, essentialFriends);
            else
                essentialFriends++;

        }
    }    
}


int main() { 
    FASTIO;
    int t;
    cin >> t;
    
    while (t--) {
        int numRooms, numFriends;
        cin >> numRooms >> numFriends;
        unordered_set<int> friends;
        friends.reserve(numFriends);
        for(int i = 0; i < numFriends; ++i) {
            int f;
            cin >> f;
            friends.insert(f);
        }
        
        vector<list<int>> graph(numRooms + 1);
        vector<int> depths(numRooms + 1);
        vector<int> distToFriend(numRooms + 1, INF);
        vector<int> leafs;
        vector<bool> visited(numRooms + 1);

        for(int i = 0; i < numRooms - 1; ++i) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        visited[1] = true;
        populateDistToFriend1(1, graph, visited, depths, distToFriend, friends, 0);
        
        fill(visited.begin() + 1, visited.end(), false);
        populateDistToFriend2(1, 0, graph, visited, distToFriend);

        fill(visited.begin() + 1, visited.end(), false);
        int essentialFriends = 0;
        bool vladCanWin = false;
        countEssentialFriends(1, graph, visited, depths, distToFriend, vladCanWin,
        essentialFriends);
                
        if(vladCanWin || essentialFriends == 0) {
            cout << -1 << "\n";
        }
        else {
            cout << essentialFriends << "\n";
        }
    }

    return 0;
}