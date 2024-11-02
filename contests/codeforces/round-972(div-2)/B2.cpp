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

        int n, m, q, x, a, ans = INF;
        cin >> n >> m >> q;
        vector<int> t(m);
        for(int i = 0; i < m; ++i)
            cin >> t[i];

        sort(t.begin(), t.end());
        
        while (q--) {
            int pos;
            cin >> pos;

            auto it_right = upper_bound(t.begin(), t.end(), pos);
            int left = t[0], right = t.back();
            
            if (pos > t.back()) {
                ans = pos - t.back() + (n - pos);
            }
            else if (pos < t[0]) {
                ans = t[0] - pos + (pos - 1);
            }
            else {
                // goes right
                int left = *it_right;
                int right = *prev(it_right);

                if (abs(pos - right) < abs(pos - left)) {
                    int a = pos - right;
                    int x = pos;
                    int y = left;
                    double k = (y - a - x) / 2.0;
                    int int_k = k;

                    ans = 0;
                    ans += int_k + a;
                    if ((int)k != int_k)
                        ans++;
                }
                else {
                    
                    int a = left - pos;
                    int x = pos;
                    int y = right;
                    double k = (x - y - a) / 2.0;
                    int int_k = k;

                    ans = 0;
                    ans += int_k + a;
                    if ((int)k != int_k)
                        ans++;
                }
            }

            cout << ans << "\n";
        }

    }
    
    return 0;
}
