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
	string s;
	std::cin >> s;

	int num0s = 0, num1s = 0;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == '1') {
			num1s++;
		}
		else {
			num0s++;
		}
	}
	
	if(num0s == num1s) {
		char num;
		if(s[0] == '0') {
			s[0] = '1';
			num = '0';
		}
		else {
			s[0] = '0';
			num = '1';
		}
		for(int i = 1; i < s.size(); i++) {
			s[i] = num;
		}
	}
	else {
		for(int i = 0; i < s.size(); i++) {
			if(num1s > num0s) { // turn all 1s into 0s
				if(s[i] == '1') s[i] = '0';
			}
			else {
				if(s[i] == '0') s[i] = '1';
			}
		}
	}
	std::cout << s << std::endl;
	return 0; 
}
