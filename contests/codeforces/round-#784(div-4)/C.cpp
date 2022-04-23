// accepted
// https://codeforces.com/contest/1669/problem/C
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
		vector<int> vec(len);
		bool isPossible = true;
		for(int i = 0; i < len; i++) {
			std::cin >> vec[i];
		}
		int oddParity, evenParity;
		evenParity = vec[0] % 2;
		oddParity = vec[1] % 2;

		for(int i = 2; i < len && isPossible; i++) {
			if(i % 2 == 0) {
				if(vec[i] % 2 != evenParity) {
					isPossible = false;
				}
			}
			else {
				if(vec[i] % 2 != oddParity) {
					isPossible = false;
				}
			}
		}

		if(isPossible) {
			std::cout << "yes" << std::endl;
		}
		else {
			std::cout << "no" << std::endl;
		}

	}	
	
	return 0; 
}
