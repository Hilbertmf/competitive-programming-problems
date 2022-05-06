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

bool isInt(float n) {
	return floor(n) == int(n);
}

int main() { 
	FASTIO;
	int t;
	std::cin >> t;
	while (t--) {
		int x, y;
		std::cin >> x >> y;
		
		
		
		int a, b = y/x;
		bool isPossible = false;
		if(x == y) {
			isPossible = true;
			a = 3;
			b = 1;
		}
		
		if(x < y) {
			if(y % x == 0) {
				isPossible = true;
				a = 1;
				b = y / x;
			}
		}
		

		if(isPossible) cout << a << " " << b << endl;
		else std::cout << "0 0" << std::endl;
	}
	return 0; 
}
