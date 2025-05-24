#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

set<int> factorize(int n) {
    set<int> factors;
    for(int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            factors.insert(i);
            factors.insert(n/i);
        }
    }
    return factors;
}

int32_t main() {
    FASTIO;

    int y, k;
    cin >> y >> k;
    int ans = 1 + gcd(y, 1);

    set<int> factors = factorize(y);
    bool is_prime = factors.size() == 0; // y

    factors.insert(y);
    
    if (k >= y) {
        if(is_prime || k < *factors.begin()) {
            k -= (y - 1);
            ans = y + (k * y);
        } else {

            k -= *factors.begin() - 1;
            ans = *factors.begin();
            vector<int> f(factors.begin(), factors.end());

            for(int j = 1; j < f.size(); ++j) {
                if (f[j] % ans == 0) {
                    k -= (f[j] - ans) / ans;
                    ans = f[j];
                }
            }

            if (k) {
                ans += (k * ans);
            }
        }

    } else {
        if(is_prime || k < *factors.begin()) {
            ans = k + 1;
        } else {

            k -= *factors.begin() - 1;
            ans = *factors.begin();
            vector<int> f(factors.begin(), factors.end());

            for(int j = 1; j < f.size() && k > 0; ++j) {
                if (f[j] % ans == 0) {
                    int aux = (f[j] - ans) / ans;
                    if (aux > k) {
                        k = 0;
                        ans += ans * k;
                    } else {
                        k -= aux;
                        ans = f[j];
                    }
                }
            }

            if (k) {
                ans += (k * ans);
            }
        }
    }

    cout << ans << "\n";
    return 0;
}

/*
time: O(sqrt(Y))
space: O(sqrt(Y))

*/ 
