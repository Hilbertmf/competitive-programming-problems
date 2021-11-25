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
	std::cin >> t;
	while (t--) {
		// its always 2 except in the edge cases
		long long row, col;
		std::cin >> row >> col;
		if(min(row, col) % 2 != 0)
			std::cout << min(row, col) +1 << std::endl;
		else
			std::cout << min(row, col) << std::endl;

	}
	
	return 0; 
}
