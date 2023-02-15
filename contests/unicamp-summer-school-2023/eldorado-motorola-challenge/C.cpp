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

void dfs(vector<int>& p, vector<int>& depths, int l, int r, int depth) {
	pair<int, int> maxN = {INF, -1};
	auto it = max_element(p.begin() + l, p.begin() + r + 1);
	maxN = {*it, it - p.begin()};
	depths[maxN.second] = depth;
	if(maxN.second - l > 0) dfs(p, depths, l, maxN.second - 1, depth + 1);
	if(r - maxN.second > 0) dfs(p, depths, maxN.second + 1, r, depth + 1);
}

int32_t main() { 
	FASTIO;
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> p(n);
		vector<int> depths(n);
		for(int i = 0; i < n; ++i) cin >> p[i];
		
		dfs(p, depths, 0, n - 1, 0);

		for(int i = 0; i < depths.size(); ++i) {
			cout << depths[i];
			if(i != depths.size() - 1) cout << " ";
		}
		cout << "\n";		
	}
		
	return 0; 
}
