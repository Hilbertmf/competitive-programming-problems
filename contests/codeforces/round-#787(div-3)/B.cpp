// accepted
// https://codeforces.com/contest/1675/problem/B
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
		int n;
		cin >> n;
		vector<long long> a(n+1);
		for(int i = 0; i < n; ++i) {
			std::cin >> a[i];
		}

		if(n == 1) {
			cout << "0" << endl;
			continue;
		}
		
		bool possible = false;
		bool increasing = false;
		bool allZeros = false;
		int op = 0;
		while(!increasing && !allZeros) {
			int operations = 0;
			for(int i = 0; i < n - 1; ++i) {
				int exponent = 0;
				if(a[i] >= a[i+1]) { // not increasing
					if(a[i+1] == 0) {
						allZeros = true;
						possible = false;
						break;
					}
					exponent = int(floor(log2(a[i])) - floor(log2(a[i+1])));
					operations += exponent;
					a[i] /= pow(2, exponent);
					if(a[i] >= a[i+1]) {
						++operations;
						a[i] /= 2;
					}
				}
				if(i == n - 2 && operations == 0) {
					increasing = true;
					possible = true;
				}
				if(a[i] == 0 && a[i+1] == 0) {
					allZeros = true;
					break;
				}
			}
			op += operations;
		}
		if(possible) std::cout << op << std::endl;
		else std::cout << -1 << std::endl;
	}	
	
	return 0; 
}
