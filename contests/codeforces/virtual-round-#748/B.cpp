// https://codeforces.com/contest/1593/problem/B
// accepted
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
		string num;
		std::cin >> num;
		int lastDigit;
		int opLast0 = 0, opLast5 = 0;
		bool last5 = false, last0 = false;
		bool hasLast5 = false, hasLast0 = false;
		
		for(int i = num.size() - 1; i >= 0; i--) {
			int digit = num[i] - '0';
			
			if(!last0 && (digit != 0)) 
				opLast0++;
			else if(!last0 && digit == 0) {
				last0 = true;
			}
			else {
				if(digit == 5 || digit == 0) {
					hasLast0 = true;
					break;
				} 
				opLast0++;
			}
		}

		for(int i = num.size() - 1; i >= 0; i--) {
			int digit = num[i] - '0';
			
			if(!last5 && (digit != 5))
				opLast5++;
			else if(!last5 && digit == 5) {
				last5 = true;
			}
			else {
				if(digit == 7 || digit == 2) {
					hasLast5 = true;
					break;
				} 
				opLast5++;
			}
		}

		int minOp;
		if(!hasLast0) minOp = opLast5;
		else if(!hasLast5) minOp = opLast0;
		else
			minOp = min(opLast0, opLast5);
		
		std::cout << minOp << std::endl;
	}
	
	return 0; 
}
