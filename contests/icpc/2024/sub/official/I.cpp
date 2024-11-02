#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define DEBUG(x) cout << #x << " >>>> " << x << endl
const int MOD = 1e9 + 7;
const int MAX_VAL = 1000000;

vector<int> getPrimes(int n) {
    vector<bool> isPrime(n + 1, true);
    vector<int> primes;
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= n; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        if (isPrime[i]) primes.push_back(i);
    }

    return primes;
}

vector<int> factorize(int n, const vector<int>& primes) {
    vector<int> factors;
    for (const int prime : primes) {
        if (prime * prime > n) break;
        if (n % prime == 0) {
            factors.push_back(prime);
            while (n % prime == 0) n /= prime;
        }
    }
    if (n > 1) factors.push_back(n);
    return factors;
}

unordered_map<int, int> precomputePrimeFrequencies(const vector<int>& nums, const vector<int>& primes) {
    unordered_map<int, int> primeFreq;

    for (int num : nums) {
        vector<int> factors = factorize(num, primes);
        for (int prime : factors) {
            primeFreq[prime]++;
        }
    }

    return primeFreq;
}

inline int lcm(int a, int b) {
    return a / __gcd(a, b) * b;
}

int countMultiples(const vector<int>& x_primes, const unordered_map<int, int>& primeFreq, int totalCount) {
    int m = x_primes.size();
    int count = 0;

    for (int i = 1; i < (1 << m); ++i) {
        int lcm_val = 1;
        int bits = __builtin_popcount(i);
        for (int j = 0; j < m; ++j) {
            if (i & (1 << j)) {
                lcm_val = lcm(lcm_val, x_primes[j]);
                if (lcm_val > MAX_VAL) break;
            }
        }
        if (lcm_val <= MAX_VAL) {
            int multiples = 0;
            auto it = primeFreq.find(lcm_val);
            if (it != primeFreq.end()) {
                multiples = it->second;
            }
            if (bits % 2 == 1) {
                count += multiples;
            } else {
                count -= multiples;
            }
        }
    }

    return totalCount - count;
}

int main() {
    FASTIO;

    const vector<int> primes = getPrimes(MAX_VAL);
    int n, q;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];

    unordered_map<int, int> primeFreq = precomputePrimeFrequencies(nums, primes);

    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        vector<int> x_primes = factorize(x, primes);

        int coprime_count = countMultiples(x_primes, primeFreq, n);

        int result = 1;
        
        DEBUG(coprime_count);
        DEBUG(n - coprime_count);
        if (coprime_count > 0) {
            result = (1LL << coprime_count) % MOD;
        }

        cout << result << "\n";
        int k = 1LL << coprime_count;
        DEBUG(k);
    }

    return 0;
}
