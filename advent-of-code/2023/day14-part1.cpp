#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> getIntervals(string& s, char separator) {

    vector<pair<int, int>> res;
    int i = s.find_first_not_of(separator);
    for(i; i < s.size(); ++i) {

        if(s[i] != '#') {
            int start = i;
            i = s.find_first_of('#', i);
            int end = (i == string::npos) ? s.size() : i;
            res.push_back({start, end});
        }

        if(i == string::npos || i == -1) break;
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

bool comp(char lhs, char rhs) {
    if(lhs != rhs && lhs == 'O')
        return true;
    return false;
}

int main() {

    string line;
    vector<string> grid;
    while (getline(cin, line)) {
        grid.push_back(line);
    }

    vector<string> grid_rotated = rotate90Deg(grid);
    int ans = 0;

    for(int r = 0; r < grid_rotated.size(); ++r) {

        vector<pair<int, int>> intervals = getIntervals(grid_rotated[r], '#');

        for(auto &[start, end] : intervals) {
            sort(grid_rotated[r].begin() + start, grid_rotated[r].begin() + end, comp);
        }

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
