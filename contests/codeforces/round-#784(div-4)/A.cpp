// accepted
// https://codeforces.com/contest/1669/problem/A
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
		int div;
		std::cin >> div;

		if(div >= 1900)
			std::cout << "Division 1" << std::endl;
		else if (div >= 1600)
			std::cout << "Division 2" << std::endl;
		else if (div >= 1400)
			std::cout << "Division 3" << std::endl;
		else 
			std::cout << "Division 4" << std::endl;	
	}
	return 0; 
}
