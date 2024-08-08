// https://codeforces.com/contest/1999/problem/F
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

int modExp(int base, int exp, int mod) {
    int result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) 
            result = (result * 1LL * base) % mod;
        exp = exp >> 1; 
        base = (base * 1LL * base) % mod; 
    }
    return result;
}

void computeFactorials(vector<int>& fact, vector<int>& invFact, int n, int mod) {
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fact[i] = (fact[i - 1] * 1LL * i) % mod;
    }
    invFact[n] = modExp(fact[n], mod - 2, mod); 
    for (int i = n - 1; i >= 0; --i) {
        invFact[i] = (invFact[i + 1] * 1LL * (i + 1)) % mod;
    }
}

int binCoef(int n, int k, vector<int>& fact, vector<int>& invFact, int mod) {
    if (k < 0 || k > n) return 0;
    int numerator = fact[n];
    int denom = (invFact[k] * 1LL * invFact[n - k]) % mod;
    return (numerator * 1LL * denom) % mod;
}

int32_t main() {
    
    const int MAX = 2e5;
    int t;
    cin >> t;

    vector<int> fact(MAX + 1);
    vector<int> invFact(MAX + 1);
    computeFactorials(fact, invFact, MAX, MOD);

    while (t--) {
    
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int ones = 0, zeros = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] == 1) ++ones;
            else ++zeros;
        }
        
        int required_ones = (k + 1) / 2;
        int ans = 0;
        
        for (int x = required_ones; x <= k; ++x) {
            if (x <= ones && (k - x) <= zeros) {
                int ways = (binCoef(ones, x, fact, invFact, MOD) *
                1LL * binCoef(zeros, k - x, fact, invFact, MOD)) % MOD;
                ans = (ans + ways) % MOD;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
