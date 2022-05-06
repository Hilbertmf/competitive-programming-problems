// accepted
// https://codeforces.com/contest/1675/problem/C
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
		string answers;
		cin >> answers;
		int numThieves = answers.size();
		if(answers[answers.size()-1] == '1') {
			std::cout << 1 << std::endl;
			continue;
		}

		int num1s = 0, num0s;
		for(const auto &ans : answers) {
			if(ans == '1') ++num1s;
			if(ans == '0') ++num0s;
		}

		if(num1s > 0 && num0s > 0) {
			numThieves = 0;
			int zeros = 0, ones = 0;
			for(const auto &ans : answers) {
				if(ans == '0') ++zeros;
				if(ans == '1') ++ones;
				if(ones == num1s && zeros <= 1) numThieves++;
				if(zeros == 1) break;
			}
		}
		else if(num0s > 0) {
			numThieves = 0;
			int zeros = 0;
			for(const auto &ans : answers) {
				if(ans == '0') ++zeros;
				if(zeros <= 1) numThieves++;
				if(zeros == 1) break;
			}
		}
		else if(num1s > 0) {
			numThieves = 0;
			int ones = 0;
			for(const auto &ans : answers) {
				if(ans == '1') ++ones;
				if(ones == num1s) numThieves++;
			}
		}
		std::cout << numThieves << std::endl;
	}	
	
	return 0; 
}
