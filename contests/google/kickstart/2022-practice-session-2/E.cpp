// https://codingcompetitions.withgoogle.com/kickstart/round/00000000008f4a94/0000000000b55465
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

struct state {
    int row;
    int col;
    int dist;
};

bool valid(int r, int c, vector<vector<char>>& grid) {
    return r >= 0 && c >= 0 && r < grid.size() && c < grid[0].size();
}

state multisourceBfs(vector<vector<char>>& grid, vector<vector<int>>& distToOffice,
vector<vector<bool>>& visited, unordered_set<string>& offices) {
    state returnPoint = (state){ -INF, -INF, -INF};
    pair<int, int> mostDistantPoint = {-INF, -INF};
    int mostDistant = -INF;
    int rows = grid.size();
    int cols = grid[0].size();
    queue<state> qu;

    for(auto &str : offices) {
        int r = stoi(str.substr(0, str.find(',')), nullptr);
        int c = stoi(str.substr(str.find(',') + 1), nullptr);
        visited[r][c] = true;
        qu.push((state){r, c, 0});
    }

    while(!qu.empty()) {
        int r = qu.front().row;
        int c = qu.front().col;
        int dist = qu.front().dist;
        qu.pop();

        if(dist > returnPoint.dist) {
            returnPoint.dist = dist;
            returnPoint.row = r;
            returnPoint.col = c;
        }

        // neighbors
        for(int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(!valid(nr, nc, grid)) continue;

            if(!visited[nr][nc]) {
                visited[nr][nc] = true;
                qu.push((state){nr, nc, dist + 1});
            }
        }
    }

    return returnPoint;
}

int main() { 
    FASTIO;
    int tests;
    cin >> tests;

    for(int t = 0; t < tests; ++t) {
        int rows, cols;
        cin >> rows >> cols;
        vector<vector<char>> grid(rows, vector<char>(cols));
        vector<vector<bool>> visited(rows, vector<bool>(cols));
        vector<vector<int>> distToOffice(rows, vector<int>(cols, -1));
        unordered_set<string> offices;

        for(int r = 0; r < rows; ++r) {
            for(int c = 0; c < cols; ++c) {
                cin >> grid[r][c];
                if(grid[r][c] == '1') {
                    offices.insert(to_string(r) + ',' + to_string(c));
                    distToOffice[r][c] = 0;
                }
            }
        }

        state point = multisourceBfs(grid, distToOffice, visited, offices);
        pair<int, int> newOffice;

        for(int r = 0; r < rows; ++r) {
            for(int c = 0; c < cols; ++c) {
                if(grid[r][c] == '1') continue;

                grid[r][c] = '1';
                for(int i = 0; i < rows; ++i)
                    for(int j = 0; j < cols; ++j) visited[i][j] = false;

                string s = to_string(r) + ',' + to_string(c);
                offices.insert(s);
                state newPoint = multisourceBfs(grid, distToOffice, visited, offices);
                grid[r][c] = '0';
                offices.erase(s);

                if(newPoint.dist < point.dist) {
                    point = newPoint;
                    newOffice = {r, c};
                }
            }
        }

        vector<pair<int, int>> possibleOffices;
        
        for(int r = 0; r < rows; ++r) {
            for(int c = 0; c < cols; ++c) {
                if(grid[r][c] == '1') continue;

                grid[r][c] = '1';
                for(int i = 0; i < rows; ++i)
                    for(int j = 0; j < cols; ++j) visited[i][j] = false;

                string s = to_string(r) + ',' + to_string(c);
                offices.insert(s);
                state newPoint = multisourceBfs(grid, distToOffice, visited, offices);
                grid[r][c] = '0';
                offices.erase(s);

                if(newPoint.dist == point.dist) {
                    possibleOffices.push_back({r, c});
                }
            }
        }        

        cout << "Case #" << t+1 << ": " << point.dist << "\n";
    }	
    
    return 0; 
}
