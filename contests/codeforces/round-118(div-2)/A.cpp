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
		int x1, p1, x2, p2;
		std::cin >> x1 >> p1;
		std::cin >> x2 >> p2;
		int n1, n2;
		n1 = (p1 > 0) ? x1 * (pow(10, p1)) : x1;
		n2 = (p2 > 0) ? x2 * (pow(10, p2)) : x2;

		DEBUG(n1);
		DEBUG(n2);

		if(n1 > n2) std::cout << ">" << std::endl;
		else if(n2 > n1) std::cout << "<" << std::endl;
		else if(n1 == n2) std::cout << "=" << std::endl;
	}
	
	return 0; 
}
