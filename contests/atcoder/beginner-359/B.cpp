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
    cin >> n;

    vector<int> a(2*n);
    map<int, int> pos;
    int ans = 0;
    for(int i = 0; i < 2 *n; ++i) {
        cin >> a[i];
        if (pos.find(a[i]) != pos.end() &&
            pos[a[i]] == i - 2) {
            ans++;
        }
        else if (pos.find(a[i]) == pos.end())
            pos[a[i]] = i;
    }

    cout << ans << "\n";

    return 0;
}