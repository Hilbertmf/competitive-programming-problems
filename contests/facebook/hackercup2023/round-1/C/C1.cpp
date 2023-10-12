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

set<int> getFactors(int p) {
	set<int> factors;

	for(int i = 1; i*i < p; ++i) {
		if(p % i == 0) {
			factors.insert(i);
			factors.insert(p / i);
		}
	}

	return factors;
}

int32_t main() { 
	FASTIO;
	int k = 1000000;

	set<int> factors = getFactors(k);
	DEBUG(factors.size());

    int t;
    cin >> t;
    int num_cases = 1;
    while (t--) {
        int n;
		cin >> n;
		string s;
		cin >> s;

		int q;
		cin >> q;
		vector<int> qvec(q);
		map<int, int> qmap;
		for(int i = 0; i < q; ++i) {
			int aux;
			cin >> aux;
			qmap[aux]++;
		}

		set<int> qset;
		for(auto &[k, v] : qmap) {
			if(v % 2 != 0)
				qset.insert(k);
		}

		


		
		for(int i = 0; i < s.size(); ++i) {
			int idx = i + 1;
			set<int> factors = getFactors(idx);

			int mul = 1;

			DEBUG(idx);

			for(auto &factor : factors) {
				
				DEBUG(factor);

				if(qset.find(factor) != qset.end()) {
					// cout << "test\n";
					// DEBUG(idx);
					mul ^= 1;
				}
			}

			if(mul == 1 && s[i] == '1') s[i] = '0';
			else if(mul == 1 && s[i] == '0') s[i] = '1';
		}

		DEBUG(s);

        cout << "Case #" << num_cases << ": ";
        num_cases++;
    }
	
	return 0; 
}
