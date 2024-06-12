// acc
// https://codeforces.com/contest/1985/problem/H1
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

class UnionFind {

public:

    vector<int> parents;
    vector<int> group_sizes;
    int num_elems;
    int num_groups;

    UnionFind(int size) {
        if (size <= 0) return;

        num_elems = size;
        num_groups = size;
        parents.resize(size);
        group_sizes.resize(size);

        for(int i = 0; i < size; ++i) {
            parents[i] = i;
            group_sizes[i] = 1;
        }
    }

    int find(int node) {

        int root = node;
        while (root != parents[root]) {
            root = parents[root];
        }

        // path compression
        while (node != parents[node]) {
            int next = parents[node];
            parents[node] = root;
            node = next;
        }

        return root;
    }

    bool isConnected(int node1, int node2) {
        return find(node1) == find(node2);
    }

    int groupSize(int node) {
        return group_sizes[find(node)];
    }

    int size() {
        return num_elems;
    }

    int numComponents() {
        return num_groups;
    }

    void join(int node1, int node2) {

        int root1 = find(node1);
        int root2 = find(node2);
        
        if (root1 == root2)
            return;

        if (group_sizes[root1] > group_sizes[root2]) {
            group_sizes[root1] += group_sizes[root2];
            parents[root2] = root1;
        }
        else {
            group_sizes[root2] += group_sizes[root1];
            parents[root1] = root2;
        }

        num_groups--;
    }
};

vector<int> dr {1, -1, 0, 0};
vector<int> dc {0, 0, 1, -1};

bool valid(int row, int col, vector<vector<char>>& grid) {
    return row >= 0 && row < grid.size() &&
           col >= 0 && col < grid[0].size();
}

int getIndex(int row, int col,
int rows, int cols) {
    return row * cols + col;
}

void joinNodes(int row, int col, UnionFind& dsu,
vector<vector<char>>& vis,
vector<vector<char>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    queue<pair<int, int>> qu;
    qu.push({row, col});
    vis[row][col] = true;

    while (!qu.empty()) {
        int r = qu.front().first;
        int c = qu.front().second;
        qu.pop();

        dsu.join(getIndex(row, col, rows, cols),
                 getIndex(r, c, rows, cols));


        for(int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (!valid(nr, nc, grid) || vis[nr][nc] || grid[nr][nc] == '.')
                continue;
            vis[nr][nc] = true;
            dsu.join(getIndex(r, c, rows, cols),
                     getIndex(nr, nc, rows, cols));
            qu.push({nr, nc});
        }
    }
}

int32_t main() {
    FASTIO;
    int t;
    cin >> t;
    
    while(t--){

        int n, m;
        cin >> n >> m;
        UnionFind dsu(n * m);
        vector<vector<char>> grid(n, vector<char>(m));
        vector<vector<char>> vis(n, vector<char>(m, false));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                cin >> grid[i][j];
            }
        }

        int count = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                count++;
                if (vis[i][j] || grid[i][j] == '.') continue;
                vis[i][j] = true;
                joinNodes(i, j, dsu, vis, grid);
            }
        }



        int max_sz = 0;
        for(int i = 0; i < n; ++i) {
            // set everyone of row i to #
            set<int> groups;
            for(int j = 0; j < m; ++j) {
                groups.insert(dsu.find(getIndex(i, j, n, m)));

                for(int d = 0; d < 4; ++d) {
                    int nr = i + dr[d];
                    int nc = j + dc[d];
                    if (!valid(nr, nc, grid) || grid[nr][nc] == '.')
                        continue;
                    groups.insert(dsu.find(getIndex(nr, nc, n, m)));
                }
            }

            int sum = 0;
            for(auto &num : groups) {
                sum += dsu.groupSize(num);
            }
            max_sz = max(max_sz, sum);
        }

        for(int j = 0; j < m; ++j) {
            // set everyone of col j to #
            set<int> groups;
            for(int i = 0; i < n; ++i) {
                groups.insert(dsu.find(getIndex(i, j, n, m)));

                for(int d = 0; d < 4; ++d) {
                    int nr = i + dr[d];
                    int nc = j + dc[d];
                    if (!valid(nr, nc, grid) || grid[nr][nc] == '.')
                        continue;
                    groups.insert(dsu.find(getIndex(nr, nc, n, m)));
                }
            }

            int sum = 0;
            for(auto &group : groups) {
                sum += dsu.groupSize(group);
            }
            max_sz = max(max_sz, sum);
        }

        cout << max_sz << "\n";
    }
    return 0;
}