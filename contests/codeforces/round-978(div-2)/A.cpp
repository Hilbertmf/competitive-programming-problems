#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

int32_t main() {
    FASTIO;
    int t;
    cin >> t;
    
    while(t--){

        int n, r;
        cin >> n >> r;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        
        sort(a.rbegin(), a.rend());
        int ans = 0;
        int rem = 0;
        r *= 2;
        for(int i = 0; i < n && r; ++i) {
            
            int cur = a[i];
            if (cur % 2 != 0) {
                cur--;
                rem++;
            }
            ans += cur;
            r -= cur;

        }


        if (r && r > rem) {
            int alone = rem;
            if (r - rem < alone) alone = r - rem;
            ans += alone;
        }

        cout << ans << "\n";
    }
    
    return 0;
}
