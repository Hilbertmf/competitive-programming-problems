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

    int n;
    string s;
    cin >> n >> s;

    int ans = 0;
    for(int i = 1; n > 2 && i <= n - 2; ++i) {
        if (s[i - 1] == '#' && s[i] == '.' && s[i + 1] == '#') {
            ans++;
            i++;
        }
    }
    cout << ans << "\n";

    return 0;
}
