// https://codeforces.com/contest/1593/problem/D
// wrong answer
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
		int n;
		std::cin >> n;
		vector<int> nums(n);
		for(int i = 0; i < n; i++) {
			std::cin >> nums[i];
		}
		sort(nums.begin(), nums.end());
		int k = -1;

		for(int i = 1; i < nums.size(); i++) {
			int diff = nums[i] - nums[i-1];
			if(diff > 0) {
				// DEBUG(nums[i]);
				// DEBUG(nums[0]);
				
				k = max(k, diff);
				// break;
			}
		}
		std::cout << k << std::endl;
	}
	
	return 0; 
}
