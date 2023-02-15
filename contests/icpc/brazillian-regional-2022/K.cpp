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
#define int long long

int32_t main() { 
	FASTIO;
	int n;
	cin >> n;
	vector<string> s(n);
	vector<int> dic(26);
	map<char, int> mp;

	for(int i = 0; i < n; ++i) {
		cin >> s[i];
		mp[s[i][0]]++;
	}

	bool possible = false;

	for(auto &str : s) {
		possible = true;
		for(auto &c : str) {
			if(mp.find(c) == mp.end()) {
				possible = false; break;
			}
		}
		if(possible) break;
	}
		
	if(possible) {
		cout << "Y" << "\n";
	}
	else {
		cout << "N" << "\n";
	}
	return 0; 
}
