// accepted
// https://codeforces.com/contest/1676/problem/C
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
 
int getDiff(string& s1, string& s2) {
	int diff = 0;
	for(int i = 0; i < s1.size(); ++i) {
		diff += abs(s1[i] - s2[i]);
	}
	return diff;
}

int main() { 
	FASTIO;
	int t;
	cin >> t;
	while (t--) {
		int numStrings, length;
		cin >> numStrings >> length;
		vector<string> strings(numStrings);
		for(auto &s : strings) {
			cin >> s;
		}

		int diff = INF;

		for(int i = 0; i < strings.size(); ++i) {
			for(int j = i+1; j < strings.size(); ++j) {
				diff = min(diff, getDiff(strings[i], strings[j]));
			}
		}
		cout << diff << endl;
	}		
	
	return 0; 
}
