// https://codeforces.com/contest/1811/problem/A
// accepted
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
	int t;
	cin >> t;
	while (t--) {
		int n, d;
		cin >> n >> d;
		string num;
		cin >> num;
		string ans;
		bool ok = false;

		for(auto &c : num) {
			if(c - '0' < d && !ok) {
				ans += d + '0';
				ok = true;
			}
			ans += c;
		}
		if(!ok) ans += d + '0';

		cout << ans << "\n";
	}	
	
	return 0; 
}
