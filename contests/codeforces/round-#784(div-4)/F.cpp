// accepted
// https://codeforces.com/contest/1669/problem/F
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
		int numCandies;
		std::cin >> numCandies;
		vector<int> candies(numCandies);
		int ans = 0;
		// best solution: time O(n) and space O(1) w/ 2 pointers:
		int i = 0, j = numCandies, sum1 = 0, sum2 = 0;
		sum1 += candies[0];
		ans = 0;
		while(i < j) {
			while(sum1 > sum2 && i+1 < j) {
				j--;
				sum2 += candies[j];
			}
			while(sum1 < sum2 && i+1 < j) {
				i++;
				sum1 += candies[i];
			}
			if(sum1 == sum2) {
				ans = max(ans, i + 1 + (numCandies - j));
				i++;
				sum1 += candies[i];
			}
			else if(i+1 == j) i++; // exit loop
		}
		
		std::cout << ans << std::endl;
		// suboptimal: time O(n) and space O(n) w/ prefix sum and hashmap:
		ans = 0;
		vector<int> prefixSumLeft(numCandies), prefixSumRight(numCandies);
		unordered_map<int, int> prefixSumRightMap;
		
		for(int i = 0; i < numCandies; i++) {
			std::cin >> candies[i];
			prefixSumLeft[i] = candies[i];
			prefixSumRight[numCandies - 1 - i] = candies[i];
		}
		for(int i = 1; i < numCandies; i++) {
			prefixSumLeft[i] += prefixSumLeft[i-1];
			prefixSumRight[i] += prefixSumRight[i-1];
		}

		for(int i = 0; i < numCandies; i++) {
			prefixSumRightMap[prefixSumRight[i]] = i;
		}
		
		for(int i = 0; i < numCandies; i++) {
			// prefix sum in left == prefix sum in right and can use the right sum
			if(prefixSumRightMap.find(prefixSumLeft[i]) != prefixSumRightMap.end() &&
					prefixSumRightMap[prefixSumLeft[i]] < numCandies - (i+1)) {
				int idx = prefixSumRightMap[prefixSumLeft[i]];
				ans = max(ans, i + idx + 2);
			}
		}
		// std::cout << ans << std::endl;	
	}
	
	return 0; 
}
