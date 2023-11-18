// https://atcoder.jp/contests/abc329/tasks/abc329_a
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
#define int long long 
const int MOD = 1e9 + 7; // 10^9 + 7 
 
int32_t main() { 
	FASTIO;

	string s;
	cin >> s;

	for(int i = 0; i < s.size(); ++i) {
		cout << s[i];
		if(i != s.size())
			cout << " ";
	}
	cout << "\n";


	return 0; 
}
