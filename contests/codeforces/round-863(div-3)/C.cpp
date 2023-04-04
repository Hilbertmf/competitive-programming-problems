// https://codeforces.com/contest/1811/problem/C
// WA
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
		vector<int> vec(n, INF);
		int minNum = INF;
		int pos = 0;
		--n;
		for(int i = 0; i < n; ++i) {
			cin >> vec[i];
			if(vec[i] < minNum) pos = i;
			minNum = min(minNum, vec[i]);
		}
		
		vector<int> ans;
		for(int i = n - 1; i >= 0; --i) {
			if(i > 0 && vec[i] < vec[i - 1]) {
				ans.push_back(vec[i]);
				DEBUG(vec[i]);
			}
			ans.push_back(vec[i]);
		}
		reverse(ans.begin(), ans.end());

		for(int i = 0; i < n; ++i) {
			cout << ans[i] << " ";
			if(i == pos) cout << "0 ";
		}

		cout << "\n";		
	}	
	
	
	return 0; 
}
