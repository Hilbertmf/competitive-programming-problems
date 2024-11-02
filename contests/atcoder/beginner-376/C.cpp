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
    vector<int> toys(n), boxes(n - 1);
    for(int i = 0; i < n; ++i) cin >> toys[i];
    for(int i = 0; i < n - 1; ++i) cin >> boxes[i];
    
    sort(boxes.begin(), boxes.end());
    sort(toys.begin(), toys.end());

    int i = n - 1, j = n - 2;
    int count = 0, ans = -1;
    for(; i >= 0 && j >= 0; --i) {
        if (boxes[j] < toys[i]) {
            ans = toys[i];
            count++;
        }
        else {
            --j;
        }
        if (count >= 2) {
            cout << -1 << "\n";
            return 0;
        }
    }

    if (count == 0)
        ans = toys[0];

    cout << ans << "\n";
    return 0;
}
