// accepted
// https://codeforces.com/contest/1676/problem/H1
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
		int length;
		cin >> length;
		vector<pair<int, int>> segments(length);
		unordered_map<int, unordered_set<int>> crossings;
		int count = 0;
		for(int i = 0; i < length; ++i) {
			int link;
			cin >> link;
			segments[i] = make_pair(i+1, link);
			crossings[i+1] = unordered_set<int>();
		}

		for(int i = 0; i < length; ++i) {
			for(int j = 0; j < length; ++j) {
				if(i == j) continue;
				int p1 = segments[i].first;
				int n1 = segments[i].second;
				int p2 = segments[j].first;
				int n2 = segments[j].second;
				if(crossings[p1].find(p2) == 
				crossings[p1].end()) {
					// if they can intersect
					if( (p1 > p2 && n1 <= n2) || (p1 < p2 && n1 >= n2) ) {
						count++;
						crossings[p1].insert(p2);
						crossings[p2].insert(p1);
					}
				}
			}
		}

		cout << count << endl;
	}
	
	return 0; 
}
