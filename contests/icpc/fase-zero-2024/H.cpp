#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

vector<int> getPrimes(int n) {
    vector<char> is_prime(n + 1, 1);
    vector<int> primes;
    is_prime[0] = 0;
    is_prime[1] = 0;

    for(int i = 2; i*i <= n; ++i) {
        if (is_prime[i] == 0) continue;
        for(int j = i*i; j <= n; j += i) {
            is_prime[j] = 0;
        }
    }

    primes.push_back(2);
    for(int i = 3; i <= n; i += 2) {
        if (is_prime[i]) primes.push_back(i);
    }
    return primes;
}

bool isPrime(int n, unordered_set<int>& primes) {
    if (n == 1) return false;
    if (primes.find(n) != primes.end())
        return true;
    
    if (n % 2 == 0) return false;

    for(int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    primes.insert(n);
    return true;
}

int32_t main() {
    FASTIO;
    int t;
    cin >> t;

    vector<int> primes_vec = getPrimes(1e7);
    unordered_set<int> primes(primes_vec.begin(), primes_vec.end());
    
    while(t--){

        int n;
        cin >> n;

        int left = n / 2, right = (n / 2) + 1;
        if (n % 2 == 0) left--;

        while (left > 0 && (isPrime(left, primes) || isPrime(right, primes))) {
            left--;
            right++;
        }

        if(left >= 1 && !isPrime(left, primes) && !isPrime(right, primes)) {
            cout << left << " " << right << "\n";
        }
        else {
            cout << "-1\n";
        }

    }
    
    return 0;
}
