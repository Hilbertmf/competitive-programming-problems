#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

vector<pair<int, int>> directions {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1}
};

int findDir(vector<pair<int, int>>& directions, pair<int, int> d) {
    for(int i = 0; i < directions.size(); ++i) {
        if(d == directions[i])
            return i;
    }
    return -1;
}

void moveTo(vector<vector<char>>& grid, pair<int, int>& curr, pair<int, int>& facing) {
    int x 
    if(curr.first + facing.first < 0)
        curr.first = grid.size() - 1;
    else if(curr.first + facing.first >= (long long)grid.size())
        curr.first = 0;
    else
        curr.first += facing.first;

    if(curr.second + facing.second < 0)
        curr.second = grid[0].size() - 1;
    else if(curr.second + facing.second >= (long long)grid[0].size())
        curr.second = 0;
    else 
        curr.second += facing.second;
}

void counterClockwise(vector<vector<char>>& grid, pair<int, int>& curr, pair<int, int>& facing) {
    int r = curr.first, c = curr.second;
    grid[r][c] = '.';
    int i = findDir(directions, facing);
    if(i == 0)
        facing = directions[3];
    else
        facing = directions[i - 1];

    moveTo(grid, curr, facing);
}

void clockwise(vector<vector<char>>& grid, pair<int, int>& curr, pair<int, int>& facing) {
    int r = curr.first, c = curr.second;
    grid[r][c] = '#';
    int i = findDir(directions, facing);
    if(i == 3)
        facing = directions[0];
    else
        facing = directions[i + 1];

    moveTo(grid, curr, facing);
}

int32_t main() {
    FASTIO;

    int rows, cols, n;
    cin >> rows >> cols >> n;
    vector<vector<char>> grid(rows, vector<char>(cols, '.'));
    pair<int, int> curr = {0, 0};
    pair<int, int> facing = {-1, 0};

    while (n--) {
        int r = curr.first, c = curr.second;
        if(grid[r][c] == '.') {
            clockwise(grid, curr, facing);
        }
        else {
            counterClockwise(grid, curr, facing);
        }
    }

    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            cout << grid[i][j];
        }
        cout << "\n";
    }

    return 0;
}
