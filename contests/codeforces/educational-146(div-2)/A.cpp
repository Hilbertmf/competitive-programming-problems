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
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;

		if(n % 2 != 0 && k % 2 == 0) {
			cout << "NO" << "\n";
		}
		else {
			cout << "YES" << "\n";
		}		
	}
	
	return 0; 
}
