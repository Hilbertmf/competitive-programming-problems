// accepted
// https://codeforces.com/contest/1669/problem/H
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
		int n, k;
		std::cin >> n >> k;
		vector<int> nums(n);

		for(int i = 0; i < n; i++) {
			std::cin >> nums[i];
		}

    for(int bit = 30; bit >= 0 && k; bit--) {
      int numsWithSetBit = 0;
      for(auto &num : nums) {
        if(num & (1 << bit)) numsWithSetBit++;
      }
      
      int cost = n - numsWithSetBit;
      if(k >= cost) {
        k -= cost;
        for(int j = 0; j < n && cost; j++) {
          if(!(nums[j] & (1 << bit))) {
            nums[j] = nums[j] | (1 << bit);
            cost--;
          }
        }
      }
    }

    int result = nums[0];
		for(int i = 1; i < n; i++) result &= nums[i];
		std::cout << result << std::endl;
  }
  return 0; 
}