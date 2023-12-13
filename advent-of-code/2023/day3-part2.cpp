#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl

vector<int> dr {1, -1, 0, 0, 1, -1, 1, -1};
vector<int> dc {0, 0, 1, -1, 1, -1, -1, 1};

bool isValid(vector<string>& grid, int r, int c) {
    return r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size();
}

void mapNumPositions(vector<string>& grid, multimap<int, vector<vector<int>>>& num_positions) {
    int rows = grid.size(), cols = grid[0].size();
    for(int r = 0; r < rows; ++r) {
        for(int p = 0; p < grid[r].size() && p >= 0; ++p) {

            auto pos = grid[r].find_first_of("0123456789", p);
            if(pos != string::npos) {
                p = pos;
                string num_str;
                vector<vector<int>> positions;

                while (p < grid[r].size() && isdigit(grid[r][p])) {
                    positions.push_back({r, p});
                    num_str += grid[r][p];
                    p++;
                }

                auto first_not_digit = find_if_not(num_str.begin(), num_str.end(),
                [](char c) {
                    return isdigit(c);
                });

                if(first_not_digit == num_str.end()) {
                    int n = stoi(num_str);
                    num_positions.insert({n, positions});
                }
                
            }
            else {
                break;
            }
        }
        
    }
}

int main() {

    string s;
    vector<string> grid;
    while (getline(cin, s)) {
        grid.push_back(s);
    }
    
    int rows = grid.size(), cols = grid[0].size();
    multimap<int, vector<vector<int>>> num_positions;
    map<vector<int>, int> map_pos_to_idx;
    map<int, int> idx_to_num;
    int ans = 0;

    mapNumPositions(grid, num_positions);
    
    int idx = 0;
    for(auto &[num, positions] : num_positions) {
        idx_to_num[idx] = num;
        for(auto &pos : positions) {
            map_pos_to_idx[pos] = idx;
        }
        idx++;
    }

    for(int r = 0; r < rows; ++r) {
        for(int c = 0; c < grid[0].size(); ++c) {
            if(grid[r][c] == '*') {

                set<int> adj_nums;
                    
                for(int i = 0; i < 8; ++i) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];

                    if(!isValid(grid, nr, nc)) continue;
                    if(isdigit(grid[nr][nc])) {
                        adj_nums.insert(map_pos_to_idx[{nr, nc}]);
                    }
                }

                if(adj_nums.size() == 2) {
                    vector<int> idxs(adj_nums.begin(), adj_nums.end());
                    ans += idx_to_num[idxs[0]] * idx_to_num[idxs[1]];
                }

            }
        }
    }

    cout << ans << "\n";
    
    return 0;
}
