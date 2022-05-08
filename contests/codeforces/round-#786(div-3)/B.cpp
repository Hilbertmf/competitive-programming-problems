// accepted
// https://codeforces.com/contest/1674/problem/B
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
	vector<string> dic;
	string w = "aa";
	for(int i = 0; i < 26; ++i) {
		w[0] = 'a' + i;
		char second;
		for(int j = 0; j < 26; ++j) {
			second = 'a' + j;
			if(w[0] != second) {
				w[1] = second;
				dic.push_back(w);
			}
			else continue;
		}
	}
	while (t--) {
		string word;
		std::cin >> word;
		int i;
		for(i = 0; i < dic.size() && word != dic[i]; ++i) {
		}

		std::cout << i+1 << std::endl;
	}
	return 0; 
}
