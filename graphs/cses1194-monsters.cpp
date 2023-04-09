// https://cses.fi/problemset/task/1194
#include <bits/stdc++.h> 
using namespace std; 
#define DEBUG(x) cout << #x << " >>>> " << x << endl 
#define MID(l, r) (l + (r - l) / 2) 
#define CEILDIVISION(x, y) ((x + y - 1) / y) 
#define INF (int)1e9 
#define LONGINF (long long)1e18 
#define MEM(arr, val) memset(arr, (val), sizeof(arr)) 
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
const int MOD = 1000000007; // 10^9 - 7 
 
vector<int> dr {1, -1, 0, 0};
vector<int> dc {0, 0, 1, -1};

bool valid(vector<vector<char>>& grid, int row, int col) {
	return row >= 0 && col >= 0 && row < grid.size() && col < grid[0].size() &&
	grid[row][col] != '#';
}

void bfs(vector<vector<char>>& grid, unordered_set<string>& exits,
map<string, int>& exitDist, vector<pair<int, int>>& startNodes,
pair<int, int> dest, vector<vector<pair<int, int>>>& par) {
	int n = grid.size();
	int m = grid[0].size();
	vector<vector<bool>> vis(n, vector<bool>(m));
	queue<pair<int, pair<int, int>>> qu;

	for(auto &p : startNodes) {
		qu.push({0, p});
	}

	while(!qu.empty()) {
		int dist = qu.front().first;
		int r = qu.front().second.first;
		int c = qu.front().second.second;
		qu.pop();

		if(dest.first != -1 && dest.second != -1) {
			if(r == dest.first && c == dest.second) break;
		}
		else {
			string str = to_string(r) + "," + to_string(c);
			if(exits.find(str) != exits.end())
				exitDist[str] = dist;
		}

		for(int i = 0; i < 4; ++i) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if(!valid(grid, nr, nc) || vis[nr][nc]) continue;
			vis[nr][nc] = true;
			qu.push({dist + 1, {nr, nc}});
			if(par.size() > 0)
				par[nr][nc] = {r, c};
		}
	}

}

string getPath(vector<vector<char>>& grid, vector<vector<pair<int, int>>>& par,
pair<int, int>& start, pair<int, int>& dest) {
	string path;

	for(pair<int, int> p = start; p != dest; p = par[p.first][p.second]) {

		if(par[p.first][p.second].first > p.first) path += 'D';
		else if(par[p.first][p.second].first < p.first) path += 'U';
		else if(par[p.first][p.second].second > p.second) path += 'R';
		else if(par[p.first][p.second].second < p.second) path += 'L';
	}
	return path;
} 

string solve(vector<vector<char>>& grid, unordered_set<string>& exits, vector<vector<pair<int, int>>>& par,
vector<pair<int, int>>& monsters, pair<int, int>& start) {
	map<string, int> exitToMonster;
	map<string, int> exitToOrigin;
	vector<vector<pair<int, int>>> aux;
	pair<int, int> exitPair = {-1, -1};

	bfs(grid, exits, exitToMonster, monsters, {-1, -1}, aux);
	vector<pair<int, int>> tmp = {start};
	bfs(grid, exits, exitToOrigin, tmp, {-1, -1}, aux);

	for(auto &[exit, dist] : exitToOrigin) {
		if(exitToMonster.find(exit) == exitToMonster.end() ||
		dist < exitToMonster[exit]) {
			exitPair = {stoi(exit.substr(0, exit.find(','))),
			stoi(exit.substr(exit.find(',') + 1))};
			break;
		}
	}

	if(exitPair.first != -1 && exitPair.second != -1) {
		tmp = {exitPair};
		map<string, int> tmpMap;
		bfs(grid, exits, tmpMap, tmp, start, par);
		string path = getPath(grid, par, start, exitPair);
		return path;
	}
	else {
		return "";
	}
}

int main() { 
	FASTIO;
	int n, m;
	cin >> n >> m;
	vector<vector<char>> grid(n, vector<char>(m));
	pair<int, int> start;
	vector<pair<int, int>> monsters;
	unordered_set<string> exits;

	for(int r = 0; r < n; ++r) {
		for(int c = 0; c < m; ++c) {
			cin >> grid[r][c];
			if(grid[r][c] == 'A') start = {r, c};
			if(grid[r][c] == 'M') monsters.push_back({r, c});
			else if((grid[r][c] == '.' || grid[r][c] == 'A') && (
				r == 0 || r == n - 1 || c == 0 || c == m - 1)) {
					exits.insert(to_string(r) + "," + to_string(c));
				}
		}
	}

	vector<vector<pair<int, int>>> par(n, vector<pair<int, int>>(m, {-1, -1}));	
	string path = solve(grid, exits, par, monsters, start);
	
	string startStr = to_string(start.first) + "," + to_string(start.second);
	if(exits.find(startStr) != exits.end()) {
		cout << "YES\n";
		cout << 0 << "\n";
	}
	else if(path.size() == 0) {
		cout << "NO\n";
	}
	else {
		cout << "YES\n";
		cout << path.size() << "\n";
		cout << path << "\n";
	}

	return 0; 
}