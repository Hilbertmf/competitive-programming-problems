// accepted
// https://codeforces.com/contest/1675/problem/A
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
		int a, b, c, x, y;
		std::cin >> a >> b >> c >> x >> y;
		bool possible = false;
		x -= a;
		y -= b;
		if(x < 0) x = 0;
		if(y < 0) y = 0;
		if(c >= x + y) possible = true;
		
		if(possible)	std::cout << "YES" << std::endl;
		else	std::cout << "NO" << std::endl;
	}
	return 0; 
}
