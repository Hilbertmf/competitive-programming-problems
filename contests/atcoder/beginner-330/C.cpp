// accepted
// https://atcoder.jp/contests/abc330/tasks/abc330_c
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

int closer(int n, int n1, int n2) {
    if(abs(n - n1) < abs(n - n2))
        return n1;
    return n2;
}

int32_t main() {
    FASTIO;

    int d;
    cin >> d;
    vector<int> sqrs;
    sqrs.push_back(0);
    sqrs.push_back(1);

    for(int i = 2; true ; ++i) {
        sqrs.push_back(i*i);

        if(i*i >= d) break;
    }

    int ans = INF;
    if(d == 1) ans = 0;
    for(int i = 0; i < sqrs.size() && d > 1; ++i) {
        if(sqrs[i] == d) {
            ans = 0;
            break;
        }
        
        int comp = d - sqrs[i];
        if(sqrs[i] < d) {
            auto it = lower_bound(sqrs.begin(), sqrs.end(), comp);
            ans = min({abs(comp - *it), abs(comp - *prev(it)), ans});
        }
        else {
            ans = min(ans, abs(sqrs[i] - d));
        }

        if(ans == 0) break;

    }

    cout << ans << "\n";

    return 0;
}
