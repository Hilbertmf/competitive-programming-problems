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

        int x, y, k;
        cin >> x >> y >> k;

        int ans_x = x / k;
        if (x % k != 0)
            ans_x++;
        int ans_y = y / k;
        if (y % k != 0)
            ans_y++;

        int ans = (ans_x * 2) - 1;
        if (ans_y >= ans_x)
            ans = ans_y * 2;
        cout << ans << "\n";


    }
    
    return 0;
}
