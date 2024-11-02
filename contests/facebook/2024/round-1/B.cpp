#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

const int MAX = 1e7 + 1;

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


int32_t main() {
    FASTIO;
    int t, tcase = 1;
    cin >> t;

    vector<int> primes_vec = getPrimes(MAX+1);
    unordered_set<int> primes(primes_vec.begin(), primes_vec.end());


    vector<int> dp(MAX + 1);
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 0;
    dp[3] = 0;
    dp[4] = 0;
    dp[5] = 2; // 5-3, 5-2

    // lets precompute:
    int last_prime = 5;
    for(int i = 6; i <= MAX; ++i) {
        dp[i] = dp[last_prime];
        if (primes.count(i)) {
            last_prime = i;
            if (primes.count(i - 2))
                dp[i]++;
        }
    }
        
    while(t--){
        int n;
        cin >> n;
        cout << "Case #" << tcase << ": " << dp[n] << "\n";
        tcase++;
    }
    
    return 0;
}
