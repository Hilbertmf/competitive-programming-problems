#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define INF 1e9

int MAX_N = 1e7;
int TOTAL_N = 2e6;
int MAX_E = 1e6;

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



pair<int, int> solve_brute(int n, int g, vector<int>& e) {
    pair<int, int> ans;
    map<int, int> mp;

    // simulate process
    int MIN = INF;
    for(int i = 1; i <= n; ++i) {
        if (e[i] < MIN) {
            MIN = e[i];
            mp[e[i]] = i;
        }
        else {
            int nxt, prev = i;
            for(auto &[k, v] : mp) {
                if (k >= e[i]) break;
                nxt = v;
                v = prev;
                prev = nxt;
            }
            mp[e[i]] = prev;
        }
    }

    // find ans
    if(mp.find(g) != mp.end()) {
        ans = {mp[g], 0};
    }
    else {
        int dist = INF, idx = 1;
        ans = {idx, dist};
        for(auto &[k, v] : mp) {
            
            int cur_dist = abs(k - g);
            if (cur_dist < dist) {
                ans = {v, cur_dist};
                dist = cur_dist;
            }
            else if (cur_dist == dist)
                ans.first = min(ans.first, v);
        }
    }
    return ans;
}

int n, g;
vector<int> e;
int gen_input() {    
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib_n(1, MAX);
    n = distrib_n(gen);
    return n;
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
    
    t = 100;

    while(t--){

        int n;
        // cin >> n;
        n = gen_input();
        DEBUG(n);

        cout << "Case #" << tcase << ": ";
        cout << dp[n] << "\n";
        tcase++;
    }
    
    return 0;
}