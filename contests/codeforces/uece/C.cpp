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

        int n;
        cin >> n;
        vector<int> a(n);
        int sum = 0;
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
            sum += a[i];
        }

        if(n == 1 || n == 2) {
            cout << -1 << "\n";
        }
        else {
            double avg = sum / (double)(n);
            int MAX = *max_element(a.begin(), a.end());
            sum -= MAX;
            int l = 0, r = 1e18, x = 1, ans = 0;

            sort(a.begin(), a.end());
            int idx = n / 2;
            
            while (l <= r) {
                x = MID(l, r);
                int new_max = MAX + x;
                int new_sum = sum + new_max;
                if (a[idx] * 2ll * n < new_sum) {
                    ans = x;
                    r = x - 1;
                }
                else {
                    l = x + 1;
                }
            }

            cout << ans << "\n";
        }

    }
    
    return 0;
}
