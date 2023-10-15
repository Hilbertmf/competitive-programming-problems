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
#define int long long
 
int32_t main() { 
	FASTIO;
	int t;
	cin >> t;
	while (t--) {
		vector<int> nums(3);
		cin >> nums[0] >> nums[1] >> nums[2];
		sort(nums.begin(), nums.end());
		bool possible = false;

		// case 1
		if(nums[0] == nums[1] && nums[0] == nums[2]) possible = true;
		// case 2
		else if(nums[0] == nums[1] && nums[2] == nums[0] * 2) possible = true;
		// case 3
		else if(nums[0] == nums[1] && nums[2] == nums[0] * 3) possible = true;
		// case 4
		else if(nums[0] == nums[1] && nums[2] == nums[0] * 4) possible = true;
		// case 5
		else if(nums[0] * 2 == nums[1] && nums[1] == nums[2]) possible = true;
		// case 6
		else if(nums[0]*2 == nums[1] && nums[0] * 3 == nums[2]) possible = true;
		

		if(possible) {
			cout << "YES" << "\n";
		}
		else {
			cout << "NO" << "\n";
		}

	}
	
	return 0; 
}
