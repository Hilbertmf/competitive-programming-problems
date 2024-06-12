// acc
// https://codeforces.com/contest/1985/problem/E
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

multiset<int> factors(int k) {
    multiset<int> res;
    res.insert(1);
    for(int i = 2; i * i <= k; ++i) {
        if (k % i == 0) {
            res.insert(i);
            if (k / i != i)
                res.insert(k / i);
        }
    }
    res.insert(k);
    return res;
}

int32_t main() {
    FASTIO;
    int t;
    cin >> t;
    
    while(t--){

        int x, y, z;
        cin >> x >> y >> z;
        long long k;
        cin >> k;

        multiset<int> fac = factors(k);
        vector<int> fact(fac.begin(), fac.end());
        int ans = 0;
        int max_comb = 0;
        vector<int> dimensions { -1, -1, -1};
        int n = fact.size();
        bool found = false;

        for(int i = 0; i < n; ++i) {
            int x1 = fact[i];
            if (x1 > x) continue;

            for(int j = 0; j < n; ++j) {
                int y1 = fact[j];
                int z1 = k / (x1 * y1);
                if (y1 > y || z1 > z) continue;
                if (x1 * y1 * z1 != k) continue;

                int curr = (x - x1 + 1) * (y - y1 + 1) * (z - z1 + 1);
                if (curr > max_comb) {
                    dimensions = {x1, y1, z1};
                    max_comb = curr;
                    found = true;
                }
            }
        }
        
        int x1 = dimensions[0];
        int y1 = dimensions[1];
        int z1 = dimensions[2];

        ans = (x - x1 + 1) * (y - y1 + 1) * (z - z1 + 1);

        if(dimensions[0] == -1 || dimensions[1] == -1 || dimensions[2] == -1 ||
           !found || ans < 0) {
            cout << 0 << "\n";
        }
        else {
            cout << ans << "\n";
        }

    }
    
    return 0;
}
