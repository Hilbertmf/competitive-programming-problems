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

void insertFactors(long long  n, set<int>& st) {
	for(int i = 1; i*i <= n; ++i) {
		if(n % i == 0) {
			if(n / i == i)
				st.insert(i);
			else {
				st.insert(i);
				st.insert(n / i);
			}
		}
	}
}
 
int32_t main() { 
	FASTIO;
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;

		if(a > b) swap(a, b);
		

		set<int> fa;
		set<int> fb;
		insertFactors(a, fa);
		insertFactors(b, fb);
		int ans = INF;

		DEBUG(fa.size());
		DEBUG(fb.size());

		for(auto factorA : fa) {
			int newans = a / factorA;

			DEBUG(factorA);

			for(auto factorB : fb) {
				int tmpAns = newans + (b / factorB);
				DEBUG(factorB);
				tmpAns += max(factorA, factorB) - 1;
				ans = min(ans, tmpAns);
				
			}
		}

		cout << ans << "\n";

	}
	
	return 0; 
}
