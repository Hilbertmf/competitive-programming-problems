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
	for(int test = 0; test < t; test++) {
	
		deque<int> pancakes;
		int n;
		std::cin >> n;
		for(int i = 0; i < n; i++) {
			int pancake;
			std::cin >> pancake;
			pancakes.push_back(pancake);
		}
		int value = 0;
		int paidPancakes = 0;
		while(!pancakes.empty()) {
			if(pancakes.front() < pancakes.back()) {
				if(pancakes.front() >= value) {
					paidPancakes++;
				}
				value = max(value, pancakes.front());
				pancakes.pop_front();
			}
			else {
				if(pancakes.back() >= value) {
					paidPancakes++;
				}
				value = max(value, pancakes.back());
				pancakes.pop_back();
			}
		}


		cout << "Case #" << test+1 << ": "  << paidPancakes << endl;
	// printf("Case #%d: %.6f\n", test+1, ans);
	}
	return 0; 
}
