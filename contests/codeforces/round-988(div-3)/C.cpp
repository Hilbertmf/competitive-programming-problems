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

bool isPrime(int n, set<int>& primes) {
    return primes.count(n);
}

int32_t main() {
    FASTIO;
    int t;
    cin >> t;

    vector<int> primes = getPrimes(200000);
    set<int> prime_set(primes.begin(), primes.end());
    
    while(t--){

        int n;
        cin >> n;

        vector<int> p;
        set<int> perm;
        set<int> odd, even;
        for(int i = 1; i <= n; i += 2) odd.insert(i);
        for(int i = 2; i <= n; i += 2) even.insert(i);

        while (!odd.empty()) {
            if (!odd.empty()) {
                p.push_back(*odd.begin());
                odd.erase(p.back());
            }
        }

        int used = 2;
        bool ok = false;
        for(auto &num : even) {
            if (!isPrime(num + p.back(), prime_set)) {
                used = num;
                even.erase(num);
                p.push_back(num);
                ok = true;
                break;
            }
        }

        while (!even.empty() && ok) {
            if (!even.empty()) {
                p.push_back(*even.begin());
                even.erase(p.back());
            }
        }

        
        for(int i = 0; i < n - 1; ++i) {
            int sum = p[i] + p[i + 1];
            if (isPrime(sum, prime_set)) {
                ok = false; break;
            }
        }

        if(ok) {
            for(auto &num : p) {
                cout << num << " ";
            }cout << "\n";
        }
        else {
            cout << -1 << "\n";
        }

    }
    
    return 0;
}
