#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl

bool valid(vector<string>& grid, int i, int j) {
    return i >= 0 && i < grid.size() && j >= 0 && j < grid.size();
}

bool isHorizontallySymmetrical(vector<string>& grid, int endl, int start_l,
int start_r, int end_r) {
    
    for(int i = start_l, j = start_r; i > endl && j < end_r; --i, ++j) {

        if(!valid(grid, i, j)) break;
        if(grid[i] != grid[j]) return false;
    }

    return true;
}

bool isVerticallySymmetrical(vector<string>& grid, int line_pos) {
    
    int sz = min(line_pos + 1, (int)(grid[0].size() - (line_pos + 1)));
    int start = line_pos - sz + 1;

    for(int i = 0; i < grid.size(); ++i) {

        string lhs = grid[i].substr(start, sz);
        string rhs = grid[i].substr(line_pos + 1, sz);
        reverse(rhs.begin(), rhs.end());
        if(lhs != rhs) return false;
    }

    return true;
}

void solve(vector<string>& grid, int &ans) {

    for(int r = 0; r < grid.size() - 1; ++r) {
        if(isHorizontallySymmetrical(grid, -1, r, r + 1, grid.size())) {
            ans += (r + 1) * 100;
            break;
        }
    }

    for(int c = 0; c < grid[0].size() - 1; ++c) {
        if(isVerticallySymmetrical(grid, c)) {
            ans += c + 1;
            break;
        }
    }

}

int main() {

    string line;
    vector<string> grid;
    int ans = 0;
    while (getline(cin, line)) {
        if(!line.empty())
            grid.push_back(line);

        if(line.empty()) {

            solve(grid, ans);
            grid.clear();
        }
    }

    solve(grid, ans);
    cout << ans << "\n";

    return 0;
}