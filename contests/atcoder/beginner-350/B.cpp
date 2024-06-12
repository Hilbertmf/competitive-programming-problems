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
    int q, n;
    cin >> n >> q;
    vector<bool> teeth(n, true);
    
    while(q--){
        int ti;
        cin >> ti;
        if(teeth[ti - 1]) {
            teeth[ti - 1] = false;
        }
        else {
            teeth[ti - 1] = true;
        }

    }

    int ans = 0;
    for(int i = 0; i < n; ++i) {
        if (teeth[i]) ans++;
    }
    cout << ans << "\n";
    
    return 0;
}
