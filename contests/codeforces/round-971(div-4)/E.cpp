#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

int getAPSum(int a1, int an, int n) {
    return ((a1 + an) * n) / 2;
}

int n, k;
int check(int i)  {
    if (i < 0 || i >= n) return INF;
    int sum1 = 0, sum2 = 0;
    int first = k, last = k + i;
    if (last >= k)
        sum1 = getAPSum(first, last, (last - first + 1));
    first = last + 1;
    last = k + n - 1;
    if (first <= k + n - 1)
        sum2 = getAPSum(first, last, (last - first + 1));
    return abs(sum1 - sum2);
}

int32_t main() {
    FASTIO;
    int t;
    cin >> t;
    
    while(t--){

        cin >> n >> k;

        int ans = INF;
        int l = 0, r = n - 1, mid = MID(l, r);

        while (l <= r) {
            mid = MID(l, r);
            // check
            int cur = check(mid);
            int left_val = check(mid - 1);
            int right_val = check(mid + 1);
            ans = min(ans, cur);

            if (left_val > cur && right_val > cur) {
                ans = cur; break;
            }
            else if (left_val > cur)
                l = mid + 1;
            else
                r = mid - 1;
        }

        cout << ans << "\n";
    }
    
    return 0;
}
