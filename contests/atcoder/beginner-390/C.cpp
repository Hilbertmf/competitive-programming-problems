#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

bool outside(int i, int j, pair<int, int> a,pair<int, int> b, pair<int, int> c, pair<int, int> d) {
    return (i < a.first && i < b.first) || (i > c.first && i > d.first) || (j < a.second && j < c.second) || (j > b.second && j > d.second);
}

int32_t main() {
    FASTIO;

    int rows, cols;
    cin >> rows >> cols;
    vector<string> grid(rows);
    int count_black = 0, count_white = 0, count_empty = 0;
    for(int i = 0; i < rows; ++i) {
        cin >> grid[i];
        for(auto &c : grid[i]) {
            if (c == '#') count_black++;
            else if (c == '.') count_white++;
            else count_empty++;
        }
    }

    bool possible = false;
    if (count_black == 0) possible = true;

    // find four sides
    pair<int, int> p1;
    bool found = false;
    for(int i = 0; i < rows && !found; ++i) {
        for(int j = 0; j < cols; ++j) {
            if (grid[i][j] == '#') {
                p1 = {i, j};
                found = true;
                break;
            }
        }
    }

    pair<int, int> p2;
    found = false;
    for(int i = 0; i < rows && !found; ++i) {
        for(int j = cols - 1; j >= 0; --j) {
            if (grid[i][j] == '#') {
                p2 = {i, j};
                found = true;
                break;
            }
        }
    }

    pair<int, int> p3;
    found = false;
    for(int i = rows - 1; i >= 0 && !found; --i) {
        for(int j = 0; j < cols; ++j) {
            if (grid[i][j] == '#') {
                p3 = {i, j};
                found = true;
                break;
            }
        }
    }

    pair<int, int> p4;
    found = false;
    for(int i = rows - 1; i >= 0 && !found; --i) {
        for(int j = cols - 1; j >= 0; --j) {
            if (grid[i][j] == '#') {
                p4 = {i, j};
                found = true;
                break;
            }
        }
    }
    
    pair<int, int> a, b, c, d;
    a.second = min(p1.second, p3.second);
    a.first = min(p1.first, p2.first);
    b.first = min(p1.first, p2.first);
    b.second = max(p2.second, p4.second);

    c.first = max(p3.first, p4.first);
    c.second = min(p3.second, p1.second);
    d.first = max(p3.first, p4.first);
    d.second = max(p4.second, p2.second);

    found = false;
    possible = true;
    for(int i = 0; i < rows && !found; ++i) {
        for(int j = 0; j < cols; ++j) {
            if (outside(i, j, a, b, c, d)) continue;
            if (grid[i][j] == '.') {
                possible = false; found = true;
            }
        }
    }


    if(possible) {
        cout << "Yes\n";
    }
    else {
        cout << "No\n";
    }
    return 0;
}
