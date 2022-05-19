// accepted
// https://codeforces.com/contest/1676/problem/G
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
 
int dfs(int node, int& count, vector<pair<char, list<int>>>& tree) {

	char color = tree[node].first;
	list<int> children = tree[node].second;
	int balance = 0;
	int currBalance = (color == 'W') ? 1 : -1;

	for(const auto &child : children) {
		int childBalance = dfs(child, count, tree);
		if(childBalance == 0) count++;
		balance += childBalance;
	}

	return balance + currBalance;
}

int main() { 
	
	FASTIO;
	int t;
	cin >> t;
	while (t--) {
		int numNodes;
		cin >> numNodes;
		vector<pair<char, list<int>>> tree(numNodes + 1);
		int root = 1;
		int count = 0;

		for(int i = 2; i <= numNodes; ++i) {
			int parent;
			cin >> parent;
			tree[parent].second.push_back(i);
		}
		for(int i = 1; i <= numNodes; ++i) {
			char color;
			cin >> color;
			tree[i].first = color;
		}

		int rootBalance = dfs(root, count, tree);
		if(rootBalance == 0) count++;
		cout << count << endl;
	}
	return 0; 
}
