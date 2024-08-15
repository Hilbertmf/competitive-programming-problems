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
    int t, count = 0;
    cin >> t;
    
    while(t--){

        int l, r, L, R;
        cin >> l >> r >> L >> R;
        count++;
        int ans = 0;
        
        if (l > L) {
            swap(l, L);
            swap(r, R);
        }

        if (r < L) {
            cout << "1\n";
        }
        else {
            ans += min(r, R) - max(l, L) + 2;

            if (R == r) ans--;
            if (L == l) ans--;
            cout << ans << "\n";
        }

    }
    
    return 0;
}
