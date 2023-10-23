// https://www.facebook.com/codingcompetitions/hacker-cup/2023/round-2/problems/A2
// accepted
#include <bits/stdc++.h> 
using namespace std; 
#define DEBUG(x) cout << #x << " >>>> " << x << endl 
#define MID(l, r) (l + (r - l) / 2) 
#define CEILDIVISION(x, y) ((x + y - 1) / y) 
#define INF (int)1e9 
#define LONGINF (long long)1e18 
#define MEM(arr, val) memset(arr, (val), sizeof(arr)) 
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
#define int long long
const int MOD = 1000000007; // 10^9 - 7 

vector<int> dr{1, -1, 0, 0};
vector<int> dc{0, 0, -1, 1};

bool valid(vector<vector<char>>& grid, int row, int col) {
    return row < grid.size() && col < grid[0].size() && row >= 0 && col >= 0;
}

// bfs
pair<int, int> search_adj_spaces(vector<vector<char>>& grid, vector<vector<bool>>& vis, int row, int col, vector<pair<int, int>>& spaces) {

    int adj_spaces = 0;
    int group_size = 1;

    queue<pair<int, int>> q;
    q.push({row, col});

    while(!q.empty()) {
        int curr_row = q.front().first;
        int curr_col = q.front().second;
        q.pop();

        for(int i = 0; i < 4; ++i) {
            int adj_row = curr_row + dr[i];
            int adj_col = curr_col + dc[i];
                
            if(valid(grid, adj_row, adj_col) && !vis[adj_row][adj_col]) {
                vis[adj_row][adj_col] = true;

                if(grid[adj_row][adj_col] == '.') {
                    adj_spaces++;
                    spaces.push_back({adj_row, adj_col});
                }
                else if(grid[adj_row][adj_col] == 'W') {
                    group_size++;
                    q.push({adj_row, adj_col});
                }
            }
        }

    }

    return {adj_spaces, group_size};
}

int32_t main() { 
    FASTIO;
    int t;
    cin >> t;
    int num_cases = 1;
    while (t--) {

        int num_rows, num_cols;
        cin >> num_rows >> num_cols;
        bool possible = false;

        vector<vector<char>> grid(num_rows, vector<char>(num_cols));
        vector<vector<bool>> vis(num_rows, vector<bool>(num_cols));
        map<string, int> score;

        for(int i = 0; i < num_rows; ++i) {
            for(int j = 0; j < num_cols; ++j) {
                cin >> grid[i][j];
            }
        }        

        for(int i = 0; i < num_rows; ++i) {
            for(int j = 0; j < num_cols && !possible; ++j) {
                
                if(grid[i][j] == 'W' && !vis[i][j]) {
                    vis[i][j] = true;
                    vector<pair<int, int>> spaces;
                    auto p = search_adj_spaces(grid, vis, i, j, spaces);
                    int adj_space = p.first;
                    int group_size = p.second;
                    
                    if(adj_space == 1) {
                        string s = to_string(spaces[0].first) + "," + to_string(spaces[0].second);
                        score[s] += group_size;
                    }

                    for(auto &pos : spaces) {
                        vis[pos.first][pos.second] = false;
                    }

                }

            }
        }

        cout << "Case #" << num_cases << ": ";		
        
        if(score.empty()) {
            cout << "0" << "\n";
        }
        else {
            int ans = 0;
            for(auto &[key, val] : score) {
                ans = max(ans, val);
            }
            cout << ans << "\n";
        }
        num_cases++;
    }
    
    return 0; 
}
