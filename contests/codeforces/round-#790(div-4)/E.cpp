// accepted
// https://codeforces.com/contest/1676/problem/E
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
 
int getLowerBoundIdx(vector<int>& vec, int target) {
	int l = 0, r = vec.size() - 1;
	int mid = MID(l, r);
	while(l <= r) {
		if((mid == 0 && vec[mid] >= target) ||
		(vec[mid] >= target && vec[mid-1] < target))
			return mid;
		if(vec[mid] < target) l = mid + 1;
		else r = mid - 1;
		mid = MID(l,r);
	}
	return -1;
}

int main() { 
	FASTIO;
	int t;
	cin >> t;
	while (t--) {
		int numCandies, numQueries;
		cin >> numCandies >> numQueries;
		vector<int> candies(numCandies);
		for(auto &candy : candies) {
			cin >> candy;
		}
		sort(candies.begin(), candies.end(), greater<int>());
		vector<int> prefix(numCandies);
		int sum = 0;
		for(int i = 0; i < candies.size(); ++i) {
			sum += candies[i];
			prefix[i] = sum;
		}
		while(numQueries--) {
			int x;
			cin >> x;
			// int pos = getLowerBoundIdx(prefix, x); // using custom func
			auto itr = lower_bound(prefix.begin(), prefix.end(), x); // using stl
			if(itr != prefix.end()) { // contains
				int pos = itr - prefix.begin();
				cout << pos + 1 << endl;
			}
			else {
				cout << -1 << endl;
			}
		}
		
	}	
	
	return 0; 
}
