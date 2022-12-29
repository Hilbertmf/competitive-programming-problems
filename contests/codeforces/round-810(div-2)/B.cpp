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
 
int main() { 
	FASTIO;
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		unordered_map<int, int> costMap;
		for(int i = 0; i < n; ++i) {
			int unhappiness;
			cin >> unhappiness;
			costMap[i] = unhappiness;
		}

		
		
		vector<pair<int, pair<int, int>>> costOfPair(m);
		vector<bool> hasPair(n);
		for(int i = 0; i < m; ++i) {
			int x, y;
			cin >> x >> y;
			x--; y--;
			hasPair[x] = true;
			hasPair[y] = true;
			costOfPair[i].first = costMap[x] + costMap[y];
			costOfPair[i].second = {x, y};
			// DEBUG(i);
			// DEBUG(x);
			// DEBUG(y);
			// DEBUG(costOfPair[i]);

		}

		sort(costOfPair.begin(), costOfPair.end(), greater<pair<int, pair<int, int>>>());
		
		int maxCakes = m;
		if(maxCakes & 1) maxCakes--;

		vector<bool> invited(n);

		for(int i = 0; i < maxCakes; ++i) {
			invited[costOfPair[i].second.first];
			invited[costOfPair[i].second.second];
		}

		for(int i = 0; i < n; ++i) {
			
		}

		int numPairs = m - maxCakes;
		if()
		int ans = 0;
		DEBUG(numPairs);
		for(int i = 0; i < numPairs; ++i) {
			ans += costOfPair[i];
		}

		cout << ans << "\n";
	}	
	
	return 0; 
}
