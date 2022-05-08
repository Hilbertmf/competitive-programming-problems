// accepted
// https://codeforces.com/contest/1675/problem/D
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

bool isLeaf(int curr, unordered_map<int, vector<int>>& children) {
    return children.find(curr) == children.end();
}

void dfs(int curr, vector<int>& path, unordered_map<int, vector<int>>& children, vector<bool>& visited, vector<vector<int>>& paths) {
    if(isLeaf(curr, children)) {
        // ++pathSize;
        path.push_back(curr);
        paths.push_back(path);
        return;
    }
    for(const auto &child : children[curr]) {
        if(!visited[curr]) {
            path.push_back(curr);
            visited[curr] = true;
            dfs(child, path, children, visited, paths);
        }
        else {
            // new path
            vector<int> newPath;
            dfs(child, newPath, children, visited, paths);
        }
    }
}

int main() { 
	FASTIO;
	int t;
	std::cin >> t;
	while (t--) {
        int numVertices;
        std::cin >> numVertices;
        vector<int> parents(numVertices+1);
        vector<bool> visited(numVertices+1);
        vector<vector<int>> paths;
        unordered_map<int, vector<int>> children;
        parents[0] = -1;
        int root;
        
        for(int i = 1; i <= numVertices; ++i) {
            std::cin >> parents[i];
            if(parents[i] == i) root = i;
        }

        // populate children
        for(int i = 1; i <= numVertices; ++i) {
            if(parents[i] == i) continue;
            if(children.find(parents[i]) == children.end()) {
                children[parents[i]] = vector<int>();
            }
            children[parents[i]].push_back(i);
        }
        
        vector<int> path;
        dfs(root, path, children, visited, paths);

        cout << paths.size() << endl;
        for(auto const &path : paths) {
            cout << path.size() << endl;
            for(auto const &node : path) {
                cout << node << " ";
            }
            cout << "\n";
        }
        cout << endl;
    }
	return 0; 
}
