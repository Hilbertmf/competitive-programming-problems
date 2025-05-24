#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

vector<int> dr {1, -1, 0, 0};
vector<int> dc {0, 0, 1, -1};

bool valid(int r, int c, vector<string>& grid) {
    return r < grid.size() && r >= 0 && c < grid[0].size() && c >= 0;
}

int32_t main() {
    FASTIO;

    int rows, cols;
    cin >> rows >> cols;
    vector<string> grid(rows);
    pair<int, int> start, end;
    bool found_start = false, found_end = false;
    for(int i = 0; i < rows; ++i) {
        cin >> grid[i];
    }

    for(int i = 0; i < rows && (!found_end || !found_start); ++i) {
        for(int j = 0; j < cols && (!found_end || !found_start); ++j) {
            if (grid[i][j] == 'S') {
                found_start = true;
                start = {i, j};
            }
            else if (grid[i][j] == 'G') {
                found_end = true;
                end = {i, j};
            }
        }
    }

    int ans = -1;
    bool vis[2][rows][cols];
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            vis[0][i][j] = vis[1][i][j] = false;
        }
    }

    queue<vector<int>> q;
    q.push({start.first, start.second, 0, 0});
    q.push({start.first, start.second, 0, 1});
    q.push({start.first, start.second, 0, 2});
    q.push({start.first, start.second, 0, 3});
    while (!q.empty()) {
        int r = q.front()[0];
        int c = q.front()[1];
        int d = q.front()[2];
        int dir = q.front()[3];
        vis[r][c] = true;
        q.pop();

        if (r == end.first && c == end.second) {
            ans = d;
            break;
        }

        for(int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (!valid(nr, nc, grid) || grid[nr][nc] == '#' || vis[nr][nc]) continue;
            if (dir == 0 && nr != r) continue;
            if (dir == 1 && nc != c) continue;
            q.push({nr, nc, d + 1, dir ^ 1});
        }
        
    }

    if (ans == -1) {

        vector<vector<char>> vis(rows, vector<char>(cols));
        for(int i = 0; i < rows; ++i) 
            for(int j = 0; j < cols; ++j) vis[i][j] = false;
        
        
        q.push({start.first, start.second, 0, 1});
        while (!q.empty()) {
            int r = q.front()[0];
            int c = q.front()[1];
            int d = q.front()[2];
            int dir = q.front()[3];
            vis[r][c] = true;
            q.pop();

            if (r == end.first && c == end.second) {
                ans = d;
                break;
            }

            for(int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (!valid(nr, nc, grid) || grid[nr][nc] == '#' || vis[nr][nc]) continue;
                if (dir == 0 && nr != r) continue;
                if (dir == 1 && nc != c) continue;
                q.push({nr, nc, d + 1, dir ^ 1});
            }
        
        }

    }


    cout << ans << "\n";
    return 0;
}
