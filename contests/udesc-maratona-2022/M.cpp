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

vector<int> dr{1, -1, 0, 0};
vector<int> dc{0, 0, 1, -1};

bool valid(int r, int c, vector<vector<char>> grid) {
    return r >= 0 && c >= 0 && r < grid.size() && c < grid[0].size();
}

void dfs(int r, int c, vector<vector<char>>& grid, vector<vector<bool>>& visited,
vector<vector<int>>& dists, queue<pair<int, int>>& neighbors, int dist) {
    dists[r][c] = dist;
    
    for(int i = 0; i < 4; ++i) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if(!valid(nr, nc, grid))
            continue;

        if(!visited[nr][nc] && grid[nr][nc] == grid[r][c]) {
            visited[nr][nc] = true;
            dfs(nr, nc, grid, visited, dists, neighbors, dist);
        }
        else if(!visited[nr][nc]){
            neighbors.push({nr, nc});
        }
    }
}


int main() { 
    FASTIO;
    int t;
    cin >> t;
    while (t--) {
        int rows, cols;
        cin >> rows >> cols;
        vector<vector<char>> grid(rows, vector<char>(cols));
        vector<vector<bool>> visited(rows, vector<bool>(cols));
        vector<vector<int>> dists(rows, vector<int>(cols, INF));

        for(int r = 0; r < rows; ++r) {
            for(int c = 0; c < cols; ++c) {
                cin >> grid[r][c];
            }
        }

        queue<pair<int, int>> neighbors;
        visited[0][0] = true;
        dists[0][0] = 0;
        dfs(0, 0, grid, visited, dists, neighbors, dists[0][0]);

        while(!visited[rows - 1][cols - 1]) {
            int r = neighbors.front().first;
            int c = neighbors.front().second;
            neighbors.pop();

            if(visited[r][c])
                continue;
            visited[r][c] = true;

            int dist = INF;
            for(int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(!valid(nr, nc, grid))
                    continue;
                dist = min(dist, dists[nr][nc] + 1);
            }

            dists[r][c] = dist;
            dfs(r, c, grid, visited, dists, neighbors, dists[r][c]);
            
        }
        cout << dists[rows - 1][cols - 1] << "\n";

    }
    
    return 0; 
}
