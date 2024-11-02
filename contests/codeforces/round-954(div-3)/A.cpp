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

        int x1, x2, x3;
        cin >> x1 >> x2 >> x3;

        int a1 = x1, a2 = x2, a3 = x3;
        a1 = abs(x1 - x1) + abs(x2 - x1) + abs(x3 - x1);
        a2 = abs(x1 - x2) + abs(x2 - x2) + abs(x3 - x2);
        a3 = abs(x1 - x3) + abs(x2 - x3) + abs(x3 - x3);
        int ans = min({a1, a2, a3});
        cout << ans << "\n";

    }
    
    return 0;
}
