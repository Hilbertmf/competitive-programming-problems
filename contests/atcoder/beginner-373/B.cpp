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

    string s;
    cin >> s;
    int cur, ans = 0;
    for(int i = 0; i < s.size(); ++i) {
        if (s[i] == 'A') {
            cur = i; break;
        }
    }

    for(int target = 'B'; target <= 'Z'; ++target) {
        int target_idx;
        for(int i = 0; i < s.size(); ++i) {
            if (s[i] == target) {
                target_idx = i; break;
            }
        }

        ans += abs(cur - target_idx);
        cur = target_idx;
    }

    cout << ans << "\n";
    return 0;
}
