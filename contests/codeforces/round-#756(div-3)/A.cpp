// https://codeforces.com/contest/1611/problem/A
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

bool isEven(char c) {
	return (c - '0') % 2 == 0;
}

int main() { 
	FASTIO;
	int t;
	std::cin >> t;
	while (t--) {
		string num;
		std::cin >> num;

		if(isEven(num[num.size()-1])) std::cout << 0 << std::endl;
		else if(isEven(num[0])) std::cout << 1 << std::endl;
		else {
			if(find_if(num.begin(), num.end(), isEven) != num.end())
				std::cout << 2 << std::endl;
			else std::cout << -1 << std::endl;
		}
	}	
	return 0; 
}
