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
    return row >= 0 && col >= 0 && row < grid.size() && col < grid[0].size() &&
    grid[row][col] != '#';
}

struct state{
    int row;
    int col;
    int dist;
    char id;
};

void addBorder(int r, int c, vector<vector<char>>& grid, unordered_set<string>& borders) {
    borders.insert(to_string(r) + "," + to_string(c));
}

vector<vector<pair<int, char>>> multisourceBfs(vector<vector<char>>& grid,
unordered_set<string>& monsters, string source) {
    vector<vector<pair<int, char>>> dists(grid.size(), vector<pair<int, char>>(grid[0].size(), {INF, '.'}));
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size()));

    queue<state> qu;
    int rowStart = stoi(source.substr(0, source.find(',')));
    int colStart = stoi(source.substr(source.find(',') + 1));
    state s = (state){rowStart, colStart, 0, 'S'};
    qu.push(s);
    dists[rowStart][colStart] = {0, 'S'};
    visited[rowStart][colStart] = true;

    for(auto &str : monsters) {
        int r = stoi(str.substr(0, str.find(',')));
        int c = stoi(str.substr(str.find(',') + 1));
        qu.push((state){r, c, 0, 'M'});
        dists[r][c] = {0, 'M'};
        visited[r][c] = true;
    }

    while (!qu.empty()) {
        int r = qu.front().row;
        int c = qu.front().col;
        int dist = qu.front().dist;
        char id = qu.front().id;
        qu.pop();

        for(int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(!valid(nr, nc, grid) || visited[nr][nc]) continue;
            
            visited[nr][nc] = true;
            if(dists[nr][nc].first > dist + 1)
                dists[nr][nc] = {dist + 1, id};
            qu.push((state){nr, nc, dist + 1, id});
        }
    }	

    return dists;
}

string constructPath(string& source, string& dest, vector<vector<char>>& grid) {
    int sourceRow = stoi(source.substr(0, source.find(',')));
    int sourceCol = stoi(source.substr(source.find(',') + 1));
    int destRow = stoi(dest.substr(0, dest.find(',')));
    int destCol = stoi(dest.substr(dest.find(',') + 1));
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size()));
    vector<vector<pair<int, int>>> parents(grid.size(), vector<pair<int, int>>(grid[0].size()));
    string path;
    queue<pair<int, int>> qu;
    visited[sourceRow][sourceCol] = true;
    qu.push({sourceRow, sourceCol});

    while (!qu.empty()) {
        int r = qu.front().first;
        int c = qu.front().second;
        qu.pop();
        if(r == destRow && c == destCol)
            break;
        
        for(int i = 0; i < 4; ++i) {
            int nr  = r + dr[i];
            int nc  = c + dc[i];
            if(!valid(nr, nc, grid) || visited[nr][nc]) continue;

            visited[nr][nc] = true;
            parents[nr][nc] = {r, c};
            qu.push({nr, nc});

        }		
    }

    parents[sourceRow][sourceCol] = {-1, -1};
    int row = destRow;
    int col = destCol;

    while(row != -1 && col != -1) {
        int pRow = parents[row][col].first;
        int pCol = parents[row][col].second;

        
        if(pRow < row) path += 'D';
        else if(pRow > row) path += 'U';
        else if(pCol > col) path += 'L';
        else if(pCol < col) path += 'R';

        auto p = parents[row][col];
        row = p.first;
        col = p.second;
    }

    reverse(path.begin(), path.end());
    return path;
}

int main() { 
    FASTIO;
    unordered_set<string> borders;
    unordered_set<string> monsters;
    string source;
    int rows, cols;
    cin >> rows >> cols;
    vector<vector<char>> grid(rows, vector<char>(cols));
    for(int r = 0; r < rows; ++r) {
        for(int c = 0; c < cols; ++c) {
            cin >> grid[r][c];
            if(grid[r][c] == 'M') {
                monsters.insert(to_string(r) + "," + to_string(c));
            }
            else if(grid[r][c] == 'A') {
                source = to_string(r) + "," + to_string(c);
            }
        }
    }

    for(int r = 0; r < rows; ++r) {

        if(r == 0 || r == rows - 1) {
            for(int c = 0; c < cols; ++c) {
                if(grid[r][c] == '.') addBorder(r, c, grid, borders);
            }
        }
        else {
            if(grid[r][0] == '.') addBorder(r, 0, grid, borders);
            if(grid[r][cols - 1] == '.') addBorder(r, cols - 1, grid, borders);
        }
    }

    // multisource bfs from monsters to borders and from borders to source
    vector<vector<pair<int, char>>> distToPlayer = multisourceBfs(grid, monsters, source);
    // then compare if theres a border closer to source than any monster mark possible as true
    bool possible = false;
    string borderStr;
    for(auto &str : borders) {
        int r = stoi(str.substr(0, str.find(',')));
        int c = stoi(str.substr(str.find(',') + 1));
        if(distToPlayer[r][c].second == 'S') {
            possible = true;
            borderStr = str;
            break;
        }
    }

    if(possible) {
        cout << "YES" << "\n";
        cout << borderStr.size() << "\n";
        string path = constructPath(source, borderStr, grid);
        cout << path.substr(1) << "\n";
    }
    else {
        cout << "NO" << "\n";
    }

    return 0; 
}
