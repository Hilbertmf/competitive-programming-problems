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

        int n, k;
        cin >> n >> k;

        if (k == 1) {
            cout << n << "\n";
        }
        else {

            int ans = 1;
            int mem = 1;
            while (mem < n) {
                mem++;
                ans += k;
            }
            
            cout << ans << "\n";
        }

    }
    
    return 0;
}
