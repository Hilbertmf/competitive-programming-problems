#include <bits/stdc++.h>
using namespace std;

vector<int> dr {1, 0, -1, 0};
vector<int> dc {0, 1, 0, -1};

bool isValid(vector<string>& grid, int r, int c) {
    return r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size();
}

bool hasCycleHelper(vector<int> pos, vector<string>& grid,
vector<vector<vector<int>>>& parents, int color,
vector<vector<int>>& colors, vector<vector<bool>>& vis, vector<int>& cycle_end) {
    bool res = false;
    int r = pos[0], c = pos[1];

    for(int i = 0; i < 4; ++i) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if(!isValid(grid, nr, nc)) continue;
        if(color == colors[nr][nc]) {
            cycle_end = {nr, nc};
            return true;
        }
        if(vis[nr][nc] || grid[nr][nc] == '.') continue;
        // L J 7 F
        if(grid[nr][nc] == 'L' &&
        !((nr > r && nc == c) || (nr == r && nc < c))) continue;
        if(grid[nr][nc] == 'J' &&
        !((nr > r && nc == c) || (nr == r && nc > c))) continue;
        if(grid[nr][nc] == '7' &&
        !((nr < r && nc == c) || (nr == r && nc > c))) continue;
        if(grid[nr][nc] == 'F' &&
        !((nr < r && nc == c) || (nr == r && nc < c))) continue;
        if(grid[nr][nc] == '|' &&
        !(nr != r && nc == c)) continue;
        if(grid[nr][nc] == '-' &&
        !(nr == r && nc != c)) continue;

        vis[nr][nc] = true;
        colors[nr][nc] = color ^ 1;
        parents[nr][nc] = {r, c};
        res |= hasCycleHelper({nr, nc}, grid, parents, color ^ 1, colors, vis, cycle_end);
        if(res) return res;
    }

    return res;
}

bool hasCycle(vector<string>& grid,
vector<vector<vector<int>>>& parents, vector<int>& start, vector<int>& cycle_end) {
    int rows = grid.size(), cols = grid[0].size();
    vector<vector<bool>> vis(rows, vector<bool>(cols));
    vector<vector<int>> colors(rows, vector<int>(cols));
    vis[start[0]][start[1]] = true;
    colors[start[0]][start[1]] = 1;

    return hasCycleHelper(start, grid, parents, 1, colors, vis, cycle_end);
}

vector<vector<int>> bfs(vector<string>& grid, vector<int>& start) {
    int rows = grid.size(), cols = grid[0].size();
    queue<vector<int>> qu;
    vector<vector<bool>> vis(rows, vector<bool>(cols));
    vector<vector<int>> dists(rows, vector<int>(cols, 0));
    qu.push({0, start[0], start[1]});
    vis[start[0]][start[1]] = true;

    while (!qu.empty()) {

        int dist = qu.front()[0];
        int r = qu.front()[1];
        int c = qu.front()[2];
        dists[r][c] = dist;
        qu.pop();

        for(int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(!isValid(grid, nr, nc) || vis[nr][nc] || grid[nr][nc] == '.') continue;
            // L J 7 F
            if(grid[nr][nc] == 'L' &&
            !((nr > r && nc == c) || (nr == r && nc < c))) continue;
            if(grid[nr][nc] == 'J' &&
            !((nr > r && nc == c) || (nr == r && nc > c))) continue;
            if(grid[nr][nc] == '7' &&
            !((nr < r && nc == c) || (nr == r && nc > c))) continue;
            if(grid[nr][nc] == 'F' &&
            !((nr < r && nc == c) || (nr == r && nc < c))) continue;
            if(grid[nr][nc] == '|' &&
            !(nr != r && nc == c)) continue;
            if(grid[nr][nc] == '-' &&
            !(nr == r && nc != c)) continue;

            vis[nr][nc] = true;
            qu.push({dist + 1, nr, nc});
        }
    }
    
    return dists;
}

int main() {

    string s;
    vector<string> grid;
    while (getline(cin, s)) {
        grid.push_back(s);
    }
    int rows = grid.size(), cols = grid[0].size();
    vector<vector<vector<int>>> parents(rows, vector<vector<int>>(cols));

    vector<int> start;
    for(int r = 0; r < rows && start.empty(); ++r) {
        for(int c = 0; c < cols; ++c) {
            parents[r][c] = {-1, -1};
            if(grid[r][c] == 'S') {
                start = {r, c};
            }
        }
    }

    // int dist = 0;
    // vector<vector<int>> dists = bfs(grid, start);

    // for(int r = 0; r < rows; ++r) {
    //     for(int c = 0; c < cols; ++c) {
    //         dist = max(dist, dists[r][c]);
    //     }
    // }
    
    // cout << dist << "\n";

    vector<int> cycle_end;

    if(hasCycle(grid, parents, start, cycle_end)) {
        cout << "Tem ciclo" << "\n";
        DEBUG(cycle_end[0]);
        DEBUG(cycle_end[1]);

        int curr_row = cycle_end[0];
        int curr_col = cycle_end[1];
        string path;

        while (isValid(grid, curr_row, curr_col) &&
        (curr_row != start[0] && curr_col != start[1])) {
            curr_row = parents[curr_row][curr_col][0];
            curr_col = parents[curr_row][curr_col][1];
            path += grid[curr_row][curr_col];
        }
        DEBUG(path);
    }
    else {
        cout << "Ñ tem ciclo" << "\n";
    }


    return 0;
}

