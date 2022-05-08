// accepted
// https://neps.academy/br/competition/1199/exercise/2008
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
	int n, m;
	std::cin >> n >> m;
	
	vector<int> a(n);
	vector<int> b(m);
	unordered_set<int> keys;
	int numChests = 0;

	for(auto &item : a) {
		std::cin >> item;
	}
	for(auto &item : b) {
		std::cin >> item;
	}
	for(auto &key : b) {
		keys.insert(key);
	}
	for(auto &key : keys) {
		for(auto &chest : a) {
			if(chest == key) numChests++;
		}
	}
	std::cout << numChests << std::endl;
	return 0; 
}
