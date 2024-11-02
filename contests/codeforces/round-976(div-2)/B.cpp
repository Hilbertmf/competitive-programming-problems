// https://codeforces.com/contest/2020/problem/B
// AC
#include <bits/stdc++.h>
using namespace std;
#define MID(l, r) (l + (r - l) / 2)
#define INF (long long)numeric_limits<long long>::max()
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long

long long check(long long n) {
    return floor(sqrtl(n));
}

int32_t main() {
    FASTIO;
    int t, k;
    cin >> t;
    
    while (t--) {
        cin >> k;
        int l = 1, r = INF, ans = -1;
        
        while (l <= r) {
            int mid = MID(l, r);
            int cur = mid - check(mid);
            
            if (cur == k) {
                ans = mid;
                r = mid - 1;
            }
            else if (cur < k) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }

        cout << ans << "\n";
    }
    
    return 0;
}
