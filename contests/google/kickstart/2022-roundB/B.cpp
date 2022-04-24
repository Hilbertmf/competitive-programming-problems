// accepted
// https://codingcompetitions.withgoogle.com/kickstart/round/00000000008caa74/0000000000acee89
#include <bits/stdc++.h> 
using namespace std; 
#define DEBUG(x) cout << #x << " >>>> " << x << endl 
#define MID(l, r) (l + (r - l) / 2) 
#define CEILDIVISION(x, y) ((x + y - 1) / y) 
#define INF (long long)1e9 
#define LONGINF (long long)1e18 
#define MEM(arr, val) memset(arr, (val), sizeof(arr)) 
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
const long long MOD = 1000000007; // 10^9 - 7 
 
long long reverseDigits(long long n) {
	long long revNum = 0;
	while(n > 0) {
			revNum = revNum * 10 + n % 10;
			n = n / 10;
	}
	return revNum;
} 

bool isPalindrome(long long n) {
	long long rev = reverseDigits(n);
	return n == rev;
}

void getFactors(long long& n, vector<long long>& factors) {
	for (int i = 1; i <= sqrt(n); i++) {
		if (n%i == 0) {
			if (n/i == i) {
				factors.push_back(i);
			}
			else {
				factors.push_back(i);
				factors.push_back(n/i);
			}
		}
	}
}

int main() { 
	FASTIO;
	long long nCases;
	std::cin >> nCases;
	for(int c = 1; c <= nCases; c++) {
		long long n;
		std::cin >> n;

		vector<long long> factors;
		long long nPalindromes = 0;
		getFactors(n, factors);
		

		for(auto &factor : factors) {
			if(isPalindrome(factor)) nPalindromes++;
		}
	
	std::cout << "Case #" << c << ": " << nPalindromes << std::endl;
	// prlong longf("Case #%d: %.6f\n", c, ans);
	}
	return 0; 
}
