#include <bits/stdc++.h>
using namespace std;

// time: O(nloglog)
// space: O(n)
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

int main() {

    int n = 1e7;
    auto primes = getPrimes(n);
    cout << primes.size() << "\n";
    return 0;
}