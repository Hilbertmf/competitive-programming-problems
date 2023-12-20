#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> getIntervals(vector<string>& grid, char separator) {

    vector<vector<pair<int, int>>> res(grid.size());

    for(int r = 0; r < grid.size(); ++r) {
        
        int i = grid[r].find_first_not_of(separator);
        for(i; i < grid[r].size(); ++i) {

            if(grid[r][i] != '#') {
                int start = i;
                i = grid[r].find_first_of('#', i);
                int end = (i == string::npos) ? grid[r].size() : i;
                res[r].push_back({start, end});
            }

            if(i == string::npos || i == -1) break;
        }
    }

    return res;
}

vector<string> rotate90Deg(vector<string>& grid) {

    vector<string> res;
    for(int c = 0; c < grid[0].size(); ++c) {
        string line;
        for(int r = 0; r < grid.size(); ++r) {
            line += grid[r][c];
        }
        res.push_back(line);
    }

    return res;
}

vector<string> rotateMinus90Deg(vector<string>& grid) {

    vector<string> rotated(grid[0].size());
    for(int r = 0; r < grid.size(); ++r) {
        for(int c = 0; c < grid[0].size(); ++c) {
            rotated[c] += grid[r][c];
        }
    }

    return rotated;
}

bool cmp(char lhs, char rhs) {
    if(lhs != rhs && lhs == 'O')
        return true;
    return false;
}

bool inverseCmp(char lhs, char rhs) {
    if(lhs != rhs && lhs == '.')
        return true;
    return false;
}

void tiltWest(vector<string>& grid,
vector<vector<pair<int, int>>>& intervals) {

    for(int r = 0; r < grid.size(); ++r) {
        for(auto &[start, end] : intervals[r]) {
            sort(grid[r].begin() + start, grid[r].begin() + end, cmp);
        }
    }
}

void tiltEast(vector<string>& grid,
vector<vector<pair<int, int>>>& intervals) {

    for(int r = 0; r < grid.size(); ++r) {
        for(auto &[start, end] : intervals[r]) {
            sort(grid[r].begin() + start, grid[r].begin() + end, inverseCmp);
        }
    }
}

void tiltNorth(vector<string>& grid,
vector<vector<pair<int, int>>>& intervals) {
    vector<string> grid_rotated = rotate90Deg(grid);
    tiltWest(grid_rotated, intervals);
    grid = rotateMinus90Deg(grid_rotated);
}

void tiltSouth(vector<string>& grid,
vector<vector<pair<int, int>>>& intervals) {

    vector<string> grid_rotated = rotate90Deg(grid);
    tiltEast(grid_rotated, intervals);
    grid = rotateMinus90Deg(grid_rotated);    
}

int main() {


    
    string line;
    vector<string> grid;
    while (getline(cin, line)) {
        grid.push_back(line);
    }


    
    vector<string> grid_rotated = rotate90Deg(grid);
    vector<vector<pair<int, int>>> intervals_horizontal = getIntervals(grid, '#');
    vector<vector<pair<int, int>>> intervals_vertical = getIntervals(grid_rotated, '#');


    set<vector<string>> visited;
    
    vector<string> curr = grid;
    list<vector<string>> parents;
    int steps = 0;

    // stop when reach a cycle
    while (visited.find(curr) == visited.end()) {

        if(steps == 0) parents.push_back(curr);
        
        visited.insert(curr);
        tiltNorth(curr, intervals_vertical);
        tiltWest(curr, intervals_horizontal);
        tiltSouth(curr, intervals_vertical);
        tiltEast(curr, intervals_horizontal);
        steps++;
        
        if(visited.find(curr) == visited.end())
            parents.push_back(curr);
    }

    auto it = parents.begin();

    // track cycle
    int operations_before_cycle = 0;
    while (it != parents.end() && *it != curr) {
        ++it;
        ++operations_before_cycle;
    }

    list<vector<string>> cycle(it, parents.end());

    int num_cycles = 1e9;
    num_cycles -= operations_before_cycle;

    int pos = num_cycles % cycle.size();
    advance(it, pos);
    vector<string> final_state = *it;
    grid_rotated = rotate90Deg(final_state);

    int ans = 0;
    for(int r = 0; r < grid_rotated.size(); ++r) {

        for(int i = 0, load = grid_rotated[r].size();
        i < grid_rotated[r].size();
        ++i, --load) {
            if(grid_rotated[r][i] == 'O')
                ans += load;
        }
    }

    cout << ans << "\n";

    return 0;
}
