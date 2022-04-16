// solved
// https://codingcompetitions.withgoogle.com/codejam/round/0000000000877ba5/0000000000aa8e9c
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
		string s;
		std::cin >> s;
		string res;

		for(int i = 0, j = i+1; i < s.size(); i++, j++) {
			if(i == s.size()-1) {
				res += s[i];
			}
			else if(s[i] == s[j]) {
				while(j < s.size() && s[i] == s[j]) {
					j++;
				}
				if(j < s.size() && s[i] < s[j]) {
					for(int k = 0; k < j-i; k++) {
						res += s[i];
					}
				}
				for(int k = 0; k < j-i; k++) {
					res += s[i];
				}
				i = j - 1;
			}
			else if(s[i] < s[j]) {
				res += s[i];
				res += s[i];
			}
			else {
				res += s[i];
			}
		}


		cout << "Case #" << test+1 << ": ";
		std::cout << res << std::endl;
	}
	
	
	return 0; 
}
