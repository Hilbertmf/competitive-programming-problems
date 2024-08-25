// https://atcoder.jp/contests/abc368/tasks/abc368_c
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

    int n, t = 0;
    cin >> n;
    vector<int> h(n);
    for(int i = 0; i < n; ++i) {
        cin >> h[i];

        while ((t + 1) % 3 != 0 && h[i] > 0) {
            t++;
            h[i]--;
        }

        if ((t + 1) % 3 == 0 && h[i] > 0) {
            t++;
            h[i] -= 3;
            if (h[i] <= 0) continue;
            t += (h[i] / 5) * 3;
            h[i] %= 5;
            if (h[i] == 4) h[i]--;
            t += h[i];
        }
    }

    cout << t << "\n";
    return 0;
}
