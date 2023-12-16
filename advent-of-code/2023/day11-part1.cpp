// time: O(rows * cols)
// space: O(rows * cols)
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl

int main() {

    string line;
    vector<string> grid;

    while (getline(cin, line)) {
        
        grid.push_back(line);
        bool all_dot = line.find_first_not_of('.') == string::npos;
        if(all_dot) {
            string dot_line = line;
            fill(dot_line.begin(), dot_line.end(), '.');
            grid.push_back(dot_line);
        }
    }

    vector<string> expanded_grid(grid.size());

    for(int c = 0; c < grid[0].size(); ++c) {
        bool all_dot = true;
        for(int r = 0; r < grid.size(); ++r) {
            
            expanded_grid[r].push_back(grid[r][c]);
            if(grid[r][c] != '.') {
                all_dot = false;
            }
        }

        if(all_dot) {
            // add new col
            for(int r = 0; r < grid.size(); ++r) {
                expanded_grid[r].push_back('.');
            }
        }
    }

    vector<pair<int, int>> galaxies;
    for(int r = 0; r < expanded_grid.size(); ++r) {
        for(int c = 0; c < expanded_grid[r].size(); ++c) {
            if(expanded_grid[r][c] == '#')
                galaxies.push_back({r, c});
        }
    }

    int sum = 0;
    
    for(int i = 0; i < galaxies.size(); ++i) {
        
        int r1 = galaxies[i].first, c1 = galaxies[i].second;

        for(int j = i + 1; j < galaxies.size(); ++j) {
            int r2 = galaxies[j].first, c2 = galaxies[j].second;
            sum += abs(r1 - r2) + abs(c1 - c2);
        }
    }

    cout << sum << "\n";

    return 0;
}