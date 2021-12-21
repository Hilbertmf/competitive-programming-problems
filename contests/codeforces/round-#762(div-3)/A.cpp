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
		string s;
		std::cin >> s;
		bool square = true;
		if(s.size() % 2 != 0) std::cout << "NO" << std::endl;
		else {
			int i = 0, j = s.size()/2;
			for(i, j; j < s.size(); i++, j++) {
				
				if(s[i] != s[j]) {
					square = false;
					break;
				}
			}
			if(square) std::cout << "YES" << std::endl;
			else std::cout << "NO" << std::endl;
		}

	}
	
	return 0; 
}
