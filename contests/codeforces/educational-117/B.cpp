// accepted
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
		int n, a, b;
		std::cin >> n >> a >> b;
		
		
		set<int> perm;
		for(int i = 1; i <= n; i++) {
			perm.insert(i);
		}

		perm.erase(a);
		perm.erase(b);
		unordered_set<int> left, right;
		left.insert(a);
		for(int i = 1; i < n/2; i++) {
			int n = *perm.rbegin();
			left.insert(n);
			perm.erase(n);
		}
		right.insert(b);
		for(int i = (n/2)+1; i < n; i++) {
			int n = *perm.begin();
			right.insert(n);
			perm.erase(n);
		}
		int maxNum = 0, minNum = INF;
		
		for(auto it = left.begin(); it != left.end(); it++) {
			minNum = min(minNum, *it);
		}
		for(auto it = right.begin(); it != right.end(); it++) {
			maxNum = max(maxNum, *it);
		}
		if(a != minNum || b != maxNum) {
			std::cout << -1 << std::endl;
		}
		else {
			// std::cout << a;
			for(auto it = left.begin(); it != left.end(); it++) {
				if(it != left.begin()) cout << " ";
				std::cout << *it;
			}
			for(auto it = right.begin(); it != right.end(); it++) {
				std::cout << " " << *it;
			}
			std::cout << std::endl;
		}
	}
	
	return 0; 
}
