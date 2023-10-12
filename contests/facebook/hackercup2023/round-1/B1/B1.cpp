#include <bits/stdc++.h> 
using namespace std; 
#define DEBUG(x) cout << #x << " >>>> " << x << endl 
#define MID(l, r) (l + (r - l) / 2) 
#define CEILDIVISION(x, y) ((x + y - 1) / y) 
#define INF (int)1e9 
#define LONGINF (long long)1e18 
#define MEM(arr, val) memset(arr, (val), sizeof(arr)) 
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
#define int long long
const int MOD = 1000000007; // 10^9 - 7 

vector<int> getPrimes(int n) {
    vector<bool> isPrime(n+1, true);
    vector<int> primes;
    isPrime[0] = false;
    isPrime[1] = false;
    
    for(int i = 2; i*i <= n; ++i) {
        if(!isPrime[i]) continue;
        
        for(int j = i*i; j <= n; j += i) {
            isPrime[j] = false;
        }
    }

    for(int i = 0; i <= n; ++i) {
        if(isPrime[i]) primes.push_back(i);
    }
    
    return primes;
}

int32_t main() { 
	FASTIO;
    int t;
    cin >> t;
    int num_cases = 1;
	vector<int> vec = getPrimes(1000000000);
	set<int> primes(vec.begin(), vec.end());

    while (t--) {
        int p;
		cin >> p;
		vector<int> a;
		int count = 0;
		set<int> factors;
		bool possible = true;

		for(int i = 1; i*i <= p; ++i) {
			if(p % i == 0) {
				int f1 = i, f2 = p / i;
				if(primes.find(f1) != primes.end()) {
					if(f1 > 41) {
						possible = false;
						break;
					}
				}
				if(primes.find(f2) != primes.end()) {
					if(f2 > 41) {
						possible = false;
						break;
					}
				}
				factors.insert(f1);
				factors.insert(f2);
			}
		}

		

        cout << "Case #" << num_cases << ": ";
		if(!possible) {
			cout << -1 << "\n";
		}
		else {

			vector<int> prime_factors;
			for(auto &fac : factors) {
				if(primes.find(fac) != primes.end())
					prime_factors.push_back(fac);
			}


			for(int i = 0; i < prime_factors.size() && possible && a.size() <= 100; ++i) {
				
				while(p != 1) {

					if(p % prime_factors[i] == 0) {
						p /= prime_factors[i];
						a.push_back(prime_factors[i]);
					}
					else
						break;
					
					if(a.size() > 100) {
						possible = false;
						break;
					}
				}


			}


			if(a.size() > 100) {
				possible = false;
			}
			
			int sum = accumulate(a.begin(), a.end(), 0);

			if(sum > 41 || !possible) {
				cout << -1 << "\n";
			}
			else {
				if(sum < 41) {
					int comp = 41 - sum;
					for(int i = 0; i < comp; ++i) {
						a.push_back(1);
					}
				}

				if(a.size() > 100) {
					cout << -1 << "\n";
				}
				else {

					cout << a.size();

					sort(a.begin(), a.end());

					for(int i = 0; i < a.size(); ++i) {
						cout << " " << a[i];
					}
					cout << "\n";
				}

			}

		}
		
        num_cases++;
    }
	
	return 0; 
}
