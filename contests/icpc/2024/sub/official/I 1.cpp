#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int MOD = 1e9 + 7; 
const int MAX_VAL = 1000000;

vector<int> getPrimes(const int n) {
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

vector<int> precomputeFrequencies(const vector<int>& nums) {
    vector<int> freq(MAX_VAL + 1, 0);
    for (const int num : nums) {
        freq[num]++;
    }    
    vector<int> multipleCount(MAX_VAL + 1, 0);
    for (int i = 1; i <= MAX_VAL; ++i) {
        for (int j = i; j <= MAX_VAL; j += i) {
            multipleCount[i] += freq[j];
        }
    }
    
    return multipleCount;
}

int countMultiples(const int x, const vector<int>& primes, const vector<int>& multipleCount) {
    const int m = primes.size();
    int count = 0;

    for (int i = 1; i < (1 << m); ++i) {
        int lcm_val = 1;
        int bits = __builtin_popcount(i);
        for (int j = 0; j < m; ++j) {
            if (i & (1 << j)) {
                lcm_val = lcm(lcm_val, primes[j]);
                if (lcm_val > MAX_VAL) break;
            }
        }
        if (lcm_val <= MAX_VAL) {
            if (bits % 2 == 1) {
                count += multipleCount[lcm_val];
            } else {
                count -= multipleCount[lcm_val];
            }
        }
    }

    return count;
}

int main() {
    FASTIO;

    const vector<int> primes = getPrimes(MAX_VAL);
    int n, q;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];

    const vector<int> multipleCount = precomputeFrequencies(nums);

    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        const vector<int> x_primes = factorize(x, primes);

        const int coprime_count = n - countMultiples(x, x_primes, multipleCount);

        int result = 1;
        for (int i = 0; i < coprime_count; ++i) {
            result = (result * 2) % MOD;
        }

        cout << result << "\n";
    }

    return 0;
}