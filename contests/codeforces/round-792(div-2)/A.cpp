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
		string n;
		cin >> n;
		if(n.size() == 2) {
			cout << n[1] << "\n";
		}
		else {
			char lesser = '9';
			lesser = min(lesser, *min_element(n.begin(), n.end()));
			cout << lesser << "\n";
		}
	}

	return 0; 
}
