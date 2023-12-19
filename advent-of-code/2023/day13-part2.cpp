#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl

bool valid(vector<string>& grid, int i, int j) {
    return i >= 0 && i < grid.size() && j >= 0 && j < grid.size();
}

bool diffByOne(string& s, string& t) {
    int num_diffs = 0;

    for(int i = 0; i < s.size(); ++i) {
        if(s[i] != t[i]) num_diffs++;
        if(num_diffs > 1) return false;
    }
    
    return num_diffs == 1;
}

bool isHorizontallySymmetrical(vector<string>& grid, int endl, int start_l,
int start_r, int end_r, int& tolerance) {
        
    for(int i = start_l, j = start_r; i > endl && j < end_r; --i, ++j) {

        if(!valid(grid, i, j)) break;
        if(grid[i] != grid[j]) {
            if(tolerance > 0 && diffByOne(grid[i], grid[j])) {
                tolerance--;
            }
            else {
                return false;
            }

        }
    }

    return true;
}

bool isVerticallySymmetrical(vector<string>& grid, int line_pos, int& tolerance) {
    
    int sz = min(line_pos + 1, (int)(grid[0].size() - (line_pos + 1)));
    int start = line_pos - sz + 1;

    for(int i = 0; i < grid.size(); ++i) {

        string lhs = grid[i].substr(start, sz);
        string rhs = grid[i].substr(line_pos + 1, sz);
        reverse(rhs.begin(), rhs.end());
        if(lhs != rhs) {
            if(tolerance > 0 && diffByOne(lhs, rhs)) {
                tolerance--;
            }
            else {
                return false;
            }
        }
    }

    return true;
}

void solve(vector<string>& grid, int &ans) {

    int tolerance;
    for(int r = 0; r < grid.size() - 1; ++r) {
        tolerance = 1;
        if(isHorizontallySymmetrical(grid, -1, r, r + 1, grid.size(), tolerance) &&
        tolerance == 0) {
            ans += (r + 1) * 100;
            break;
        }
    }

    for(int c = 0; c < grid[0].size() - 1; ++c) {
        tolerance = 1;
        if(isVerticallySymmetrical(grid, c, tolerance) &&
        tolerance == 0) {
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