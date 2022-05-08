// accepted
// https://codeforces.com/contest/1669/problem/E
// time: O(n)
// space: O(n)
#include <bits/stdc++.h> 
using namespace std; 
#define DEBUG(x) cout << #x << " >>>> " << x << endl 
#define MID(l, r) (l + (r - l) / 2) 
#define CEILDIVISION(x, y) ((x + y - 1) / y) 
#define INF (long long)1e9 
#define LONGINF (long long)1e18 
#define MEM(arr, val) memset(arr, (val), sizeof(arr)) 
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
const long long MOD = 1000000007; // 10^9 - 7 
 
int main() { 
	FASTIO;
	long long t;
	std::cin >> t;
	while (t--) {
		int numStrings;
		std::cin >> numStrings;
		vector<string> strings(numStrings);
		unordered_map<char, long long> count0;
		unordered_map<char, long long> count1;
		unordered_map<string, long long> duplicates;
		for(int i = 0; i < numStrings; ++i) {
			std::cin >> strings[i];
			count0[strings[i][0]]++;
			count1[strings[i][1]]++;
			duplicates[strings[i]]++;
		}

		long long ans = 0;
		for(const auto &s : strings) {
			long long pairs = 0;
			pairs += count0[s[0]] - 1; // dont count itself
			pairs += count1[s[1]] - 1;
			ans += pairs;
		}
		//remove duplicates
		for(const auto &s : strings) {
			ans -= 2*(duplicates[s] - 1);
		}

		std::cout << ans / 2 << std::endl;
	}
	
	return 0; 
}
