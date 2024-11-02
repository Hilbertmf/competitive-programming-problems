// WA
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// #define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

int32_t main() {
    FASTIO;
    int t;
    cin >> t;
    
    while(t--){

        int n, m, k, w;
        cin >> n >> m >> k >> w;
        vector<int> h(w);
        for(int i = 0; i < w; ++i) cin >> h[i];
        
        sort(h.rbegin(), h.rend());
        int ans = 0;
        vector<int> mul;

            if (k == n || k == m) {
                if (k == m)
                    swap(n, m);
                
                for(int j = 0; j < n; ++j) {

                    vector<int> tmp(m);
                    int mid = (m + 1) / 2;
                    for(int i = 0; i < mid; ++i) {
                        tmp[i] = min(i + 1, k);
                        tmp[m - i - 1] = min(i + 1, k);
                    }

                    for(auto &num : tmp) {
                        mul.push_back(num);
                    }
                }

            }
            else {

                for(int i = 0; i < n; ++i) {
                    for(int j = 0; j < m; ++j) {
                        int horizontal = min({i + 1, n - i, k});
                        int vertical = min({j + 1, m - j, k});
                        int cur = horizontal * vertical;
                        mul.push_back(cur);
                    }
                }

            }
            
            sort(mul.rbegin(), mul.rend());
            for(int i = 0; i < min(n * m, w); ++i)
                ans += h[i] * mul[i];
        cout << ans << "\n";
    }
    
    return 0;
}
