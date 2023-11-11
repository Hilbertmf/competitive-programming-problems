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
const int MOD = 1e9 + 7; // 10^9 + 7 
 
int32_t main() { 
	FASTIO;
	int a, b, c;

	cin >> a >> b >> c;

	map<int, int> mp;
	mp[a]++;
	mp[b]++;
	mp[c]++;

	if(mp.find(5) != mp.end() && mp.find(7) != mp.end() && mp[5] == 2 && mp[7] == 1) {
		cout << "YES" << "\n";
	}
	else {
		cout << "NO" << "\n";
	}
	
	return 0; 
}
