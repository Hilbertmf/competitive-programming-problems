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

        string s, t;
        cin >> s >> t;
        int ans = s.size();

        int common = 0;
        for(int i = 0; i < s.size() && i < t.size(); ++i) {
            if (s[i] != t[i]) {
                common = i;
                break;
            }
            else common = i + 1;
        }

        if (common) {
            ans++;
        }
        ans += (t.size() - common);
        cout << ans << "\n";

    }
    
    return 0;
}
