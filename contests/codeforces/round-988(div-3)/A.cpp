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
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int ans = 0;
        set<int> s;
        for(int i = 0; i < n - 1; ++i) {
            if (s.count(i)) continue;
            for(int j = i + 1; j < n; ++j) {
                if (s.count(i) || s.count(j)) continue;
                if (a[i] != a[j]) continue;
                s.insert(i);
                s.insert(j);
                ans++;
                break;
            }
        }

        cout << ans << "\n";
    }
    
    return 0;
}
