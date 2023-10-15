#include <bits/stdc++.h> 
using namespace std; 
#define DEBUG(x) cout << #x << " >>>> " << x << endl 
#define MID(l, r) (l + (r - l) / 2) 
#define CEILDIVISION(x, y) ((x + y - 1) / y) 
#define INF (int)1e9 
#define LONGINF (long long)1e18 
#define MEM(arr, val) memset(arr, (val), sizeof(arr)) 
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
const int MOD = 1000000007; // 10^9 + 7 
const long double EPS = 0.0000000001;
#define int long long

void factorize(int n, map<int, int>& prime_occ) {
	while(n % 2 == 0) {
		prime_occ[2]++;
		n /= 2;
	}

	for(int i = 3; i * i <= n; i += 2) {
		while(n % i == 0) {
			prime_occ[i]++;
			n /= i;
		}
	}

	if(n > 2) prime_occ[n]++;
}

int32_t main() { 
	FASTIO;
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		map<int, int> prime_occ;
		bool possible = true;

		for(int i = 0; i < n; ++i) {
			int k;
			cin >> k;
			factorize(k, prime_occ);
		}

		for(auto &[prime, occ] : prime_occ) {
			if(occ % n != 0) {
				possible = false;
				break;
			}
		}

		if(possible) {
			cout << "YES" << "\n";
		}
		else {
			cout << "NO" << "\n";
		}

	}	
	
	return 0; 
}
