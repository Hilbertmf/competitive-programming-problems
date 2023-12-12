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
    
    multimap<int, vector<vector<int>>> num_positions;

    mapNumPositions(grid, num_positions);
    

    int sum = 0;

    for(auto &[num, positions] : num_positions) {
        int curr_sum = 0;
        for(auto &p : positions) {
            int r = p[0];
            int c = p[1];

            for(int i = 0; i < 8; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(!isValid(grid, nr, nc)) continue;
                if(!isdigit(grid[nr][nc]) && grid[nr][nc] != '.') { // is a symbol
                    curr_sum += num;
                    break;
                }
            }

            if(curr_sum > 0) break;
        }
        
        sum += curr_sum;
    }

    cout << sum << "\n";
    
    return 0;
}
