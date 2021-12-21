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
		int n;
		std::cin >> n;
		if(n == 1) {
			std::cout << 1 << std::endl;
			continue;
		}
		int limitSquare = floor(sqrt(n)), limitCube = floor(cbrt(n));
		int num = 1, count = 0;
		while(num <= n && count < 100) {
			count++;
			num = pow(count, 6);
		}
		count = (num > n) ? count - 1 : count;
		int ans = limitSquare + limitCube - count;
		std::cout << ans << std::endl;
		
	}
	
	return 0; 
}
