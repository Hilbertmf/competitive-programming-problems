// https://codeforces.com/contest/1811/problem/B
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
		int n, x1, x2, y1, y2;
		cin >> n >> x1 >> y1 >> x2 >> y2;

		if(x1 != y1) {
			if(x1 < y1 &&  y1 <= n - (x1 - 1))
				y1 = x1;
			else if(x1 > y1 && y1 >= n - (x1 - 1))
				y1 = x1;
			else
				x1 = y1;

		}
		if(x1 > n / 2) {
			x1 = n - x1 + 1;
			y1 = n - y1 + 1;
		}

		if(x2 != y2) {
			if(x2 < y2 && y2 <= n - (x2 - 1))
				y2 = x2;
			else if(x2 > y2 && y2 >= n - (x2 - 1))
				y2 = x2;
			else
				x2 = y2;
		}
		if(x2 > n / 2) {
			x2 = n - x2 + 1;
			y2 = n - y2 + 1;
		}

		int ans = min(abs(x1 - x2), abs(y1 - y2));
		cout << ans << "\n";

	}	
		
	return 0; 
}
