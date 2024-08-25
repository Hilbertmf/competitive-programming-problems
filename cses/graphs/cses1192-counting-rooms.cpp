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

void traverse(int row, int col, vector<vector<char>>& grid, vector<vector<bool>>& visited) {

    for(int i = 0; i < 4; ++i) {
        int nr = row + dr[i];
        int nc = col + dc[i];
        if(!valid(nr, nc, grid) || visited[nr][nc] || grid[nr][nc] != '.')
            continue;

        visited[nr][nc] = true;
        traverse(nr, nc, grid, visited);
    }
}

int main() { 
    FASTIO;
    int rows, cols;
    cin >> rows >> cols;

    vector<vector<char>> grid(rows, vector<char>(cols));
    vector<vector<bool>> visited(rows, vector<bool>(cols));
    

    for(int r = 0; r < rows; ++r) {
        for(int c = 0; c < cols; ++c) {
            cin >> grid[r][c];
        }
    }
    
    int numRooms = 0;

    for(int r = 0; r < rows; ++r) {
        for(int c = 0; c < cols; ++c) {
            if(!visited[r][c] && grid[r][c] == '.') {
                visited[r][c] = true;
                numRooms++;
                traverse(r, c, grid,  visited);
            }
        }
    }

    cout << numRooms << "\n";

    return 0; 
}
