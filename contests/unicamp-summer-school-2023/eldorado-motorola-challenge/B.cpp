// acc
// contest: https://vjudge.net/contest/540086#overview
#include <bits/stdc++.h> 
using namespace std; 
#define DEBUG(x) cout << #x << " >>>> " << x << endl 
#define MID(l, r) (l + (r - l) / 2) 
#define CEILDIVISION(x, y) ((x + y - 1) / y) 
#define INF (int)1e9 
#define LONGINF (long long)1e18 
#define MEM(arr, val) memset(arr, (val), sizeof(arr)) 
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
#define int long long
const int MOD = 1000000007; // 10^9 - 7 

int32_t main() { 
	FASTIO;
	int n, m;
	cin >> n >> m;
	vector<vector<int>> grid(n, vector<int>(m));

	int sum = 0;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			cin >> grid[i][j];

	for(int i = n - 1; i >= 0; --i) {
		for(int j = m - 1; j >= 0; --j) {
			if(grid[i][j] == 0) 
				grid[i][j] = min(grid[i+1][j], grid[i][j+1]) - 1;
			sum += grid[i][j];
		}
	}

	bool possible = true;

	for(int i = 0; i < n && possible; ++i)
		for(int j = 0; j < m - 1 && possible; ++j)
			if(grid[i][j] >= grid[i][j + 1]) possible = false;

	for(int i = 0; i < m && possible; ++i)
		for(int j = 0; j < n - 1 && possible; ++j)
			if(grid[j][i] >= grid[j + 1][i]) possible = false;

	if(possible)
		cout << sum << "\n";
	else
		cout << "-1\n";

	return 0; 
}



class Solution {
public:
	bool dfs(int node, vector<vector<int>>& graph, vector<char>& visited,
	vector<char>& recStack) {
    if (!visited[node]) {
        visited[node] = true;
        recStack[node] = true;

        for (int neighbor : graph[node]) {
            if (!visited[neighbor] && dfs(neighbor, graph, visited, recStack))
                return true;
            else if (recStack[neighbor])
                return true;
        }
    }
    recStack[node] = false;
    return false;
	}

	bool hasCycle(vector<vector<int>>& graph) {
		int n = graph.size();
		vector<char> visited(n, false);
		vector<char> recStack(n, false);
		for (int i = 0; i < n; i++)
			if (dfs(i, graph, visited, recStack))
				return true;

		return false;
	}

    void bfs(vector<vector<int>>& tree, vector<char>& seen,
	vector<int>& order) {
		queue<pair<int, int>> qu;
		qu.push({0, -1});
		seen[0] = true;

		while (!qu.empty()) {
			int v = qu.front().first;
			int dist = qu.front().second;
			order[v] = dist;
			qu.pop();

			for(int adj : tree[v]) {
				if (seen[adj]) continue;
				seen[adj] = true;
				qu.push({adj, dist + 1});
			}
		}
	}
	
	vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> row_tree(k + 1);
		set<vector<int>> row_cond_set;
		for(auto &vec : rowConditions) row_cond_set.insert(vec);
		vector<char> is_present(k + 1);
		vector<char> seen(k + 1);
		for(auto &vec : row_cond_set) {
			row_tree[vec[0]].push_back(vec[1]);
			seen[vec[1]] = true;
			is_present[vec[0]] = is_present[vec[1]] = true;
		}
		for(int i = 1; i <= k; ++i)
			if (!seen[i] && is_present[i])
				row_tree[0].push_back(i);
		
		fill(seen.begin(), seen.end(), false);
		vector<vector<int>> col_tree(k + 1);
		set<vector<int>> col_cond_set;
		for(auto &vec : colConditions) col_cond_set.insert(vec);
		for(auto &vec : col_cond_set) {
			col_tree[vec[0]].push_back(vec[1]);
			seen[vec[1]] = true;
		}
		for(int i = 1; i <= k; ++i)
			if (!seen[i])
				col_tree[0].push_back(i);

		if (hasCycle(row_tree) || hasCycle(col_tree))
			return {};
		vector<int> row(k + 1, k - 1);
		vector<int> col(k + 1, k - 1);

		fill(seen.begin(), seen.end(), false);
		bfs(row_tree, seen, row);
		fill(seen.begin(), seen.end(), false);
		bfs(col_tree, seen, col);

		vector<vector<int>> matrix(k, vector<int>(k));


		// sort(row.begin(), row.end(), cmp);
		// sort(row.begin(), row.end(), [&col](int a, int b) {
		// 	if (a == b)
		// 	return col[a] < col[b];
		// });

		
		set<pair<int, int>> pairs;
		vector<int> incr(k);
		vector<vector<int>> tmp;
		for(int i = 1; i <= k; ++i) {
			tmp.push_back({row[i], col[i], i});
			// pair<int, int> p = {row[i], col[i]};
			// if (pairs.count(p)) {
			// 	if (p.first < k - 1)
			// 		p.first++;
			// }
			
			// if (matrix[row[i]][col[i]] != 0) {
			// 	// incr[row[i]]++;
			// 	matrix[row[i] + aux][col[i] + aux] = i;
			// 	aux++;
			// }
			// else {
			// 	matrix[row[i]][col[i]] = i;
			// }
		}

		sort(tmp.begin(), tmp.end());
		set<pair<int, int>> vis;
		int aux = 1;

		for(auto &vec : tmp) {
			int num = vec[2];
			int r = vec[0];
			int c = vec[1];

			cout << "i: " << num << "| row: " << r << "| col: " << c << "\n";

			while (vis.count({r, c})) {
				r++;
				c++;
			}
			matrix[r][c] = num;

			vis.insert({r, c});
		}

		return matrix;
    }
};

// 1: 

// ith bit:

// return (num >> (i - 1)) & 1;

// 2:

// set ith bit:

// mask = 1 << (i - 1)
// return num | mask;

// 3:

// set ith bit

// mask = ~(1 << (i - 1))
// return num & mask;

/*

each node can be visited no more than 2 times



0 1 2 3 4  ;    t / c = 0
5 6 7 8 9  ;    t / c = 1
10 11 12 13 14 ;t / c = 2

time / change = 

if t / c % 2 == 0 ok
else d = (t / c) * c + c

   - 2' - 4'
 1 
 | |
 3 3'

*/


class Solution {
public:

	int numTeams(vector<int>& rating) {
        
    }
};