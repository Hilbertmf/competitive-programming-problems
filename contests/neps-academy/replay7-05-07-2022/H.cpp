// accepted
// https://neps.academy/br/competition/1199/exercise/2012
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
	int n;
	std::cin >> n;
	vector<int> a(n);
	int count[2001] = {0};
	for(int i = 0; i < 2001; ++i) {
		count[i] = INF;
	}
	for(int i = 0; i < n; ++i) {
		std::cin >> a[i];
		if(count[a[i]] == INF) count[a[i]] = 1;
		else count[a[i]]++;
	}
	int occ = INF;
	int ans;
	for(int i = 2000; i >= 0; --i) {
		if(count[i] <= occ) {
			occ = count[i];
			ans = i;
		}
	}
	std::cout << ans << std::endl;
	return 0; 
}
