// accepted
// https://codeforces.com/contest/1669/problem/B
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
	std::cin >> t;
	while (t--) {
		int len;
		std::cin >> len;
		unordered_map<int, int> values;
		for(int i = 0; i < len; i++) {
			int val;
			std::cin >> val;
			values[val]++;
		}
		for(auto it = values.begin(); it != values.end(); it++) {
			if(it->second >= 3) {
				std::cout << it->first << std::endl;
				break;
			}
			else if(next(it) == values.end()) std::cout << -1 << std::endl;
		}
	}
	
	return 0; 
}
