// TLE
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

long long dfs(int node, vector<list<int>>& graph, vector<bool>& visited) {
    long long size = 1;

    for(auto &neighbor : graph[node]) {
        if(!visited[neighbor]) {
            visited[neighbor] = true;
            size += dfs(neighbor, graph, visited);
        }
    }

    return size;
}

int main() { 
    FASTIO;
    int n, m, q;

    cin >> n >> m >> q;

    vector<list<int>> graph(n);
    vector<int> computers(q);

    vector<string> nonLinks(m);
    for(int i = 0; i < m; ++i) {
        string link, str1, str2;
        cin >> str1 >> str2;
        link = str1 + " " + str2;
        nonLinks[i] = link;
    }
    
    unordered_set<string> nonExistentLinks;
    nonExistentLinks.reserve(m*2);

    for(auto &link : nonLinks) {
        nonExistentLinks.insert(link);
        string rev = link;
        reverse(rev.begin(), rev.end());
        nonExistentLinks.insert(rev);
    }

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(i == j) continue;

            string link = to_string(i+1) + " " + to_string(j+1);
            if(nonExistentLinks.find(link) == nonExistentLinks.end())
                graph[i].push_back(j);
        }
    }

    vector<long long> islandSizes;
    vector<bool> visited(n);

    for(int i = 0; i < n; ++i) {
        if(!visited[i]) {
            visited[i] = true;
            long long size = dfs(i, graph, visited);
            islandSizes.push_back(size);
        }
    }

    sort(islandSizes.begin(), islandSizes.end(), greater<int>());


    for(int i = 1; i < n; ++i) {
        islandSizes[i] += islandSizes[i - 1];
    }

    int computer;
    for(int i = 0; i < q; ++i) {
        cin >> computer;
        if(computer == 0)
            cout << 0 << "\n";
        else if(computer >= islandSizes.size())
            cout << islandSizes[islandSizes.size() - 1] << "\n";
        else
            cout << islandSizes[computer - 1] << "\n";
    }
    

    
    return 0;
}
