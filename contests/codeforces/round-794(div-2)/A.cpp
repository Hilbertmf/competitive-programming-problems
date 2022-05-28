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
		int n;
		cin >> n;
		vector<double> vec(n);
		bool possible = false;
		double sum = 0;
		for(auto &item : vec) {
			cin >> item;
			sum += item;
		}

		for(int i = 0; !possible && i < n; ++i) {
			double mean = (sum - vec[i]) / double(n - 1);
			if(vec[i] == mean) possible = true;
		}

		if(possible) cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}	
	
	return 0; 
}
