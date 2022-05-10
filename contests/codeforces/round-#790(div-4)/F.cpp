// accepted
// https://codeforces.com/contest/1676/problem/F
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

void setNewSolution(int left, int right, int& currDiff, pair<int, int>& sol) {
	currDiff = right - left;
	sol.first = left;
	sol.second = right;
}

int main() { 
	FASTIO;
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<long long> arr(n);
		for(auto &item : arr) {
			cin >> item;
		}

		sort(arr.begin(), arr.end());
		pair<int, int> sol(-1, -1);
		int l = arr[0], r = arr[0];
		int count = 0;
		int currDiff = 0;
		for(int i = 0; i < arr.size(); ++i) {
			if(arr[i] == l || arr[i] == r) {
				count++;
			}
			else {
				if(r - l >= currDiff)
					setNewSolution(l, r, currDiff, sol);
				if(!(count >= k && arr[i] == arr[i-1] + 1)) // not consecutive
					l = arr[i]; // new left
				
				r = arr[i];
				count = 1;
			}
		}
		if(count >= k && r - l >= currDiff) {
			setNewSolution(l, r, currDiff, sol);
		}
		
		if(sol.first == -1 || sol.second == -1) 
			cout << -1 << endl;
		else
			cout << sol.first << " " << sol.second << endl;
	}	
	
	return 0; 
}
