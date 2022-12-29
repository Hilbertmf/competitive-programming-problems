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

bool valid(int row, int col, vector<vector<char>>& grid) {
    return row >= 0 && col >= 0 && row < grid.size() && col < grid[0].size();
}

bool bfs(pair<int, int>& start, pair<int, int>& end, vector<vector<char>>& grid,
vector<vector<pair<int, int>>>& parents) {
    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<bool>> visited(rows, vector<bool>(cols));
    queue<pair<int, int>> qu;
    qu.push(start);
    visited[start.first][start.second] = true;
    parents[start.first][start.second] = {-1, -1};

    while(!qu.empty()) {
        int r = qu.front().first;		
        int c = qu.front().second;
        qu.pop();

        if(r == end.first && c == end.second) 
            return true;

        for(int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(!valid(nr, nc, grid) || visited[nr][nc] || grid[nr][nc] == '#')
                continue;

            visited[nr][nc] = true;
            qu.push({nr, nc});
            parents[nr][nc] = {r, c};
        }

    }

    return false;
}

void reconstructPath(vector<vector<pair<int, int>>>& parents, pair<int, int> start,
pair<int, int> end, string& path) {
    int r = end.first;
    int c = end.second;

    while(!(r == start.first && c == start.second)) {
        int prow = parents[r][c].first;
        int pcol = parents[r][c].second;

        char dir;

        if(prow > r)
            dir = 'U';
        else if(prow < r)
            dir = 'D';
        else if(pcol < c)
            dir = 'R';
        else
            dir = 'L';

        path += dir;

        r = prow;
        c = pcol;
    }

    reverse(path.begin(), path.end());
}

int main() { 
    FASTIO;
    int rows, cols;
    cin >> rows >> cols;
    vector<vector<char>> grid(rows, vector<char>(cols));
    pair<int, int> start, end;

    for(int r = 0; r < rows; ++r) {
        for(int c = 0; c < cols; ++c) {
            cin >> grid[r][c];
            if(grid[r][c] == 'A') start = {r, c};
            if(grid[r][c] == 'B') end = {r, c};
        }
    }

    vector<vector<pair<int, int>>> parents(rows, vector<pair<int, int>>(cols));
    string path;
    bool possible = bfs(start, end, grid, parents);

    if(possible) {
        cout << "YES" << "\n";
        reconstructPath(parents, start, end, path);
        cout << path.size() << "\n";
        cout << path << "\n";
    }
    else {
        cout << "NO" << "\n";
    }
    
    return 0; 
}
