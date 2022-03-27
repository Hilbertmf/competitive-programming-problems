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

bool isPrime(int num, set<int> primes) {
	if(primes.find(num) != primes.end()) // has found
		return true;
	return false;
}

int main() { 
	FASTIO;
	int t;
	std::cin >> t;
	bool auxPrimes[31623+1];
	// works fast enough up to 10^7
	vector<bool> primes(10000001, true);

	// standard sieve to find who is prime
	memset(auxPrimes, true, sizeof(auxPrimes));
	for(int p = 2; p*p < 31623; p++) {
		if(auxPrimes[p]) {
			for(int i = p*p; i < 31623; i += p) {
				auxPrimes[i] = false;
			}
		}
	}
	
	vector<int> auxPrimesVec(3401);
	for(int i = 2, j = 0; i < 31623; i++) {
		if(auxPrimes[i]) {
			auxPrimesVec[j] = i;
			j++;
		}
	}
	cout << auxPrimesVec.size() << endl;
	for(int p = 0; p <= 3400; p++) {
		for(int i = auxPrimesVec[p] * auxPrimesVec[p]; i <= 10000000; i += auxPrimesVec[p]) {
			primes[i] = false;
		}
	}

	set<int> primesTree;
	
	for(int i = 2; i < primes.size(); i++) {
		if(primes[i]) {
			primesTree.insert(i);
		}
	}

	while (t--) {
		int n;
		std::cin >> n;
		if(n <= 5) std::cout << -1 << std::endl;
		else {
			int x, y;
			bool yPrime = true;

			for(auto it = primesTree.begin(); it != primesTree.end() && yPrime; it++) {
				x = *it;
				y = n - x;
				
				if(!isPrime(y, primesTree)) yPrime = false;
			}

			std::cout << x << " " << y << std::endl;
		}
	}
	
	return 0; 
}
