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
		vector<int> seq(n);
		int numOdds = 0, numEven = 0;
		for(auto &num : seq) {
			cin >> num;
			if(num % 2 == 0)
				numEven++;
			else
				numOdds++;
		}

		if(numEven > numOdds) {
			cout << numOdds << "\n";
		}
		else {
			cout << numEven << "\n";
		}

	}	
	
	return 0; 
}
