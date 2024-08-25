// https://atcoder.jp/contests/abc368/tasks/abc368_b
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
    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int op = 0;
    while (true) {
        int count = 0;
        for(int i = 0; i < n; ++i) {
            count += a[i] > 0;
        }
        if (count <= 1) break;
        sort(a.rbegin(), a.rend());
        a[0]--; a[1]--;
        op++;
    }

    cout << op << "\n";


    return 0;
}
