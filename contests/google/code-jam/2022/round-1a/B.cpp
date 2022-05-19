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
		int n;
		std::cin >> n;
		int sum = 0;

		vector<int> a(n);
		vector<int> b(n);
		vector<int> nums(n*2);
		for(int i = 0, val = 2; i < n; i++, val += 2) {
			a[i] = val;
			sum += val;
		}
		
		// for(auto &n : a) {
		// 	std::cout << n << " ";
		// }
		// std::cout << std::endl;
		for(int i = 0; i < n; i++) {
			std::cin >> b[i];
			sum += b[i];
		}
		DEBUG(sum);
		int idx = 0;
		for(int i = 0; i < n; i++, idx++) {nums[idx] = a[i];
		}
		for(int i = 0; i < n; i++, idx++) {
			nums[idx] = b[i];
		}

		std::sort(nums.begin(), nums.end());

		int cache[(n*2)+1][(sum/2)+1];
		memset(cache, 0, sizeof(cache));

		for(int num = 0; num <= n*2; num++) {
			for(int w = 0; w <= sum/2; w++) {
				int currWeight = nums[num-1];
				int currValue = nums[num-1];
				// base cases
				if (num == 0 || w == 0)
					cache[num][w] = 0;
				// if it weighs more than capacity we cannot use the item
				else if (currWeight > w)
					cache[num][w] = cache[num-1][w];
				else {
					int includeIth = currValue + cache[num-1][w - currWeight];
					int excludeIth = cache[num-1][w];
					cache[num][w] = max(includeIth, excludeIth);
				}
			}	
		}
		
		if(cache[n*2][sum/2] == sum/2) {
			vector<int> solution;
			// populate solution:
			for (int i = n*2, w = sum/2; i > 0 && w > 0; i--) {
				int currWeight = nums[i-1];
				int include = currWeight + cache[i-1][w-currWeight];

				if (cache[i][w] == include) {
					solution.push_back(currWeight);
					w -= currWeight;
				}
			}

			std::cout << "log" << std::endl;
			
			for(auto &item : solution) std::cout << item << " ";
			
			std::cout << std::endl;
		}


		cout << "Case #" << test+1 << ": ";
		// std::cout << res << std::endl;
	}	
	
	return 0; 
}
