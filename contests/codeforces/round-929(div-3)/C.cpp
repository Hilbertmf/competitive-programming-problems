#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

long long power(long long a, long long b) {
    if(b == 0) return 1;
    if(b == 1) return a;
 
    long long res = power(a, b / 2);
    res = (res * res);
    if(b % 2 == 1)
        res *= a;
    return res;
}

int32_t main() {
    FASTIO;
    int t;
    cin >> t;

    while(t--){

        int a, b, l;
        cin >> a >> b >> l;

        int ans = 0;

        if((a > l && b > l) || ((l % a != 0) && (l % b != 0))) {
            cout << 1 << "\n";
        }
        else {
            if(a == b && l % a == 0) {
                while (l > 0) {
                    l /= a;
                    ans++;
                }
            }
            else {
                
                for(int x = 0; power(a, x) <= l; ++x) {
                    if (l % power(a, x) != 0) continue;
                    int curr = l / power(a, x);
                    for(int y = 0; power(b, y) <= curr; ++y) {
                        ans += curr % power(b, y) == 0;
                    }
                }
            }

            cout << max(ans, 1ll) << "\n";
        }

    }

    return 0;
}
