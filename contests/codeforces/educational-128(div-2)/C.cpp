// wrong answer
// https://codeforces.com/contest/1680/problem/C
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
	cin >> t;

	while (t--) {
		string s;
		cin >> s;
		int num0s = 0;
		int removed1s = 0;
		int cost;
		vector<int> idxs0;
		idxs0.reserve(s.size());
		int start = 0;
		int end = s.size() - 1;

		for(int i = 0; i < s.size(); ++i) {
			if(s[i] == '0') {
				num0s++;
				idxs0.push_back(i);
			}
		}

		int i = 0, j = idxs0.size() - 1;
		if(idxs0.size() > 1 && idxs0[1] == idxs0[0] + 1 && idxs0[0] == 0) {
			int idx;
			for(idx = 1; num0s && idx < idxs0.size(); ++idx) {
				if(idxs0[idx] == idxs0[idx-1] + 1) {
					i = idx + 1;
					start = idxs0[idx];
					--num0s;
				}
			}
			
			if(idx < s.size()) {
				++start;
				--num0s;
			}
		}

		if(idxs0.size() > 1 && idxs0[idxs0.size() - 1] == idxs0[idxs0.size() - 2] + 1 &&
		idxs0[idxs0.size() - 1] == s.size() - 1) {
			int idx;
			for(idx = idxs0.size() - 1; num0s && idx >= 1; --idx) {
				if(idxs0[idx] == idxs0[idx-1] + 1) {
					j = idx - 2;
					end = idxs0[idx-1];
					--num0s;
				}
			}

			if(idx > 0){
				--end;
				--num0s;
			}
		}
		

		cost = max(num0s, removed1s);
		// DEBUG(num0s);
		// DEBUG(removed1s);
		// DEBUG(cost);
		// DEBUG(start);
		// DEBUG(end);
		// DEBUG(idxs0[i]);
		// DEBUG(idxs0[j]);


		while (!(s[start] == '1' && s[end] == '1' && num0s == removed1s) &&
		start < end && i < j ) {
			// DEBUG(start);
			// DEBUG(end);
			// DEBUG(idxs0[i]);
			// DEBUG(idxs0[j]);

			if( (abs(idxs0[i] - start)) < (abs(end - idxs0[j]))) {
				removed1s += abs(idxs0[i] - start);
				int step = abs(idxs0[i] - start) + 1;
				start += step;
				--i;
				--num0s;
			}

			else {
				removed1s += abs(idxs0[j] - end);
				int step = abs(idxs0[j] - end) + 1;
				end -= step;
				--j;
				--num0s;
			}
			// DEBUG(start);
			// DEBUG(end);
			// DEBUG(idxs0[i]);
			// DEBUG(idxs0[j]);

			
			// DEBUG(num0s);
			// DEBUG(removed1s);
			cost = min(cost, max(num0s, removed1s));
			// DEBUG(cost);
			// cout << endl;
		}

		cout << cost << endl;
	}	
	
	return 0; 
}
