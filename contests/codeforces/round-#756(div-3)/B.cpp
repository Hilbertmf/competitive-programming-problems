// https://codeforces.com/contest/1611/problem/B
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
const int MOD = 1000000007; // 10^9 - 7 
 
int main() { 
	FASTIO;
	int t;
	std::cin >> t;
	while (t--) {
		long long a, b;
		std::cin >> a >> b;

		if(a == 0 || b == 0)
			std::cout << 0 << std::endl;
		else {
			long long sum = a+b;
			long long ans = min(sum / 4, min(a,b));
			std::cout << ans << std::endl;
		}
	}
	
	return 0; 
}
