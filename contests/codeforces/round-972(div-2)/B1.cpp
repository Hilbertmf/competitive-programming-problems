#include <bits/stdc++.h>
using namespace std;
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
#define DEBUG(x) cout << #x << " >>>> " << x << endl

int32_t main() {
    FASTIO;
    int t;
    cin >> t;
    
    while(t--){

        int n, m, q, x, a, ans;
        cin >> n >> m >> q;
        int t[m];
        for(int i = 0; i < m; ++i)
            cin >> t[i];

        sort(t, t + 2);
        
        while (q--) {
            int pos;
            cin >> pos;

            int left = t[0], right = t[1];
            if (pos < left)
                ans = left - pos + (pos - 1);
            else if (pos > right)
                ans = pos - right + (n - pos);
            else {
                ans = 0;
                int x = pos;
                double k;
                if (abs(pos - left) < abs(pos - right)) {
                    a = pos - left;
                    int y = right;
                    k = (y - a - x) / 2.0;
                }
                else {
                    a = right - pos;
                    int y = left;
                    k = (x - y - a) / 2.0;
                }
                int int_k = k;
                ans += (int)k + a;
                if (int_k != (int)k)
                    ans++;
            }

            cout << ans << "\n";
        }

    }
    
    return 0;
}
