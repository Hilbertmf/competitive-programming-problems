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

        int n, m;
        cin >> n >> m;
        string a, b;
        cin >> a >> b;

        int j = 0;
        int i = 0;
        int ans = 0;
        while (i < n && j < m) {
            
            while (i < n && j < m && a[i] != b[j]) {
                j++;
            }

            if (i < n && j < m && a[i] == b[j]) {
                ans++;
                i++;
                j++;
            }
        }

        cout << ans << "\n";

    }
    
    return 0;
}
