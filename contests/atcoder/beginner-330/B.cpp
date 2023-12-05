// accepted
// https://atcoder.jp/contests/abc330/tasks/abc330_b
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

    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    
    for(int i = 0; i < n; ++i) {
        if(a[i] < l)
            cout << l << " ";
        else if(a[i] > r)
            cout << r << " ";
        else
            cout << a[i] << " ";
    }
    cout << "\n";

    return 0;
}
