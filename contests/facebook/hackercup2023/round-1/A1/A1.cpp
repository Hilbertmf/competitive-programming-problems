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
#define eps 0.000001
const int MOD = 1000000007; // 10^9 - 7 

int32_t main() { 
	FASTIO;
    int t;
    cin >> t;
    int num_cases = 1;
    while (t--) {
		int n;
		cin >> n;
		vector<int> x(n);
		for(int i = 0; i < n; ++i) {
			cin >> x[i];
		}

		sort(x.begin(), x.end());

		double ans;

		if(n == 5) {
			ans = max(((x[2] + x[4] - x[0] - x[1]) / 2.0),
			((x[3] + x[4] - x[0] - x[2]) / 2.0));
		}
		else {
			ans = ((x[n-2] + x[n-1] - x[0] - x[1])) / 2.0;
		}


        cout << "Case #" << num_cases << ": ";
		cout << fixed;  
		cout << setprecision(6) << ans << "\n";
        num_cases++;
    }
	
	return 0; 
}
