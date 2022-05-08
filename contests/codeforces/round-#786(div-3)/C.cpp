// accepted
// https://codeforces.com/contest/1674/problem/C
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
 
bool contains(char c, string& s) {
	for(const auto &item : s) {
		if(c == item) return true;
	}
	return false;
}

int main() { 
	FASTIO;
	int t;
	std::cin >> t;
	while (t--) {
		string s;
		string t;
		std::cin >> s >> t;
		int ans = 1;

		if(t.size() == 1 && t[0] == 'a')
			std::cout << 1 << std::endl;
		else if(t.size() > 1 && contains('a', t)) {
			std::cout << -1 << std::endl;
		}
		else {
			long long ans = pow(2,s.size());
			std::cout << ans << std::endl;
		}
	}
	return 0; 
}
