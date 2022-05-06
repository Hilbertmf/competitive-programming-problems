#include <bits/stdc++.h> 
using namespace std; 
#define MID(l, r) (l + (r - l) / 2) 
#define CEILDIVISION(x, y) ((x + y - 1) / y) 
#define INF (int)1e9 
#define LONGINF (long long)1e18 
#define MEM(arr, val) memset(arr, (val), sizeof(arr)) 
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
const int MOD = 1000000007; // 10^9 - 7 

bool comp(pair<int, int>& a, pair<int, int>& b) {
	return a.second < b.second;
}

int main() { 
	FASTIO;
	int t;
	std::cin >> t;
	while (t--) {
		int n;
		std::cin >> n;
		vector<int> a(n);
		bool isPossible = true;
		unordered_multimap<int, int> indices;

		for(int i = 0; i < n; ++i) {
			std::cin >> a[i];
		}
		
		vector<int> sorted = a;
		sort(sorted.begin(), sorted.end());
		for(int i = 0; i < n; ++i) indices.insert(make_pair(a[i], i));
		
		
		for(int i = 0; isPossible && i < n; ++i) {
			auto range = indices.equal_range(sorted[i]);
			int j = i;
			vector<pair<int, int>> sortedRange;
			for(auto it = range.first; it != range.second; ++it, ++j) {
				sortedRange.push_back(make_pair(it->first, it->second));
			}
			sort(sortedRange.begin(), sortedRange.end(), comp);
			for(j = i; j - i < indices.count(sorted[i]) && isPossible; ++j) {
				if(sortedRange[j-i].second > j+1) isPossible = false;
			}
			i = j - 1;
		}

		if(n <= 2) std::cout << "YES" << std::endl;
		else {
			if(isPossible) std::cout << "YES" << std::endl;
			else std::cout << "NO" << std::endl;
		}
	}
	return 0; 
}
