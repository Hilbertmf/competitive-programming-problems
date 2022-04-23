// accepted
// https://codeforces.com/contest/1669/problem/D
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
		int len;
		std::cin >> len;

		string cells;
		std::cin >> cells;
		bool isPossible = true;
		
		/*
		if size == 2 and s[0] == 'W' or s[1] == 'W': false
		if all letters are the same and not W: false
		if we have a letter surrounded by W: false
		if we have subarr of equal letters surrounded by W: false
		*/
		int numB = 0, numR = 0;
		for(int i = 0; i < len; i++) {
			if(cells[i] != 'W') {
				numB = 0, numR = 0;

				for(i = i; i < len && cells[i] != 'W'; i++) {
					if(cells[i] == 'B') numB++;
					if(cells[i] == 'R') numR++;
				}
				if(numB == 0 || numR == 0) isPossible = false;
			}
		}

		if(isPossible) std::cout << "yes" << std::endl;
		else std::cout << "no" << std::endl;
	}	
	
	return 0; 
}
