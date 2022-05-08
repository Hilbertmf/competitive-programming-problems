// accepted
// https://neps.academy/br/competition/1199/exercise/2014
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
	int a, b, s;
	int base = 250;
	std::cin >> s >> a >> b;
	
	if(s <= a) std::cout << base << std::endl;
	else std::cout << base + (ceil((s - a) / float(b)))*100 << std::endl;
	
	return 0; 
}
