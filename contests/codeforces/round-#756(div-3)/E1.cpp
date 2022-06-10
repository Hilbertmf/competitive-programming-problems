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

void getLeafs(int node, vector<list<int>>& graph, vector<bool>& visited, vector<int>& depths,
vector<int>& distToFriend, vector<int>& leafs, unordered_set<int>& friends, int depth) {
    depths[node] = depth;
    if(isLeaf(node, graph)) {
        leafs.push_back(node);
    }
    if(friends.find(node) != friends.end()) {
        distToFriend[node] = 0;
    }

    for(auto &neighbor : graph[node]) {
        if(!visited[neighbor]) {
            visited[neighbor] = true;
            getLeafs(neighbor, graph, visited, depths, distToFriend, leafs, friends, depth + 1);
            distToFriend[node] = min(distToFriend[node], distToFriend[neighbor] + 1);

        }
    }
}

void populateDistToFriend(int node, int parent, vector<list<int>>& graph, vector<bool>& visited,
vector<int>& distToFriend) {
    distToFriend[node] = min(distToFriend[node], distToFriend[parent] + 1);
    
    for(auto &neighbor : graph[node]) {
        if(!visited[neighbor]) {
            visited[neighbor] = true;
            populateDistToFriend(neighbor, node, graph, visited, distToFriend);

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
        getLeafs(1, graph, visited, depths, distToFriend, leafs, friends, 0);
        fill(visited.begin(), visited.end(), false);
        visited[1] = true;
        populateDistToFriend(1, 0, graph, visited, distToFriend);

        bool possible = false;
        for(const auto &leaf : leafs) {

            if(distToFriend[leaf] > depths[leaf]) {
                possible = true;
                break;
            }
        }


        for(int i = 1; i < graph.size(); ++i) {
           DEBUG(i);
            DEBUG(depths[i]);
            DEBUG(distToFriend[i]);
        }


        if(possible) {
            cout << "YES" << "\n";
        }
        else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}