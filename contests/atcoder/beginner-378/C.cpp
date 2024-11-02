// https://atcoder.jp/contests/abc378/tasks/abc378_c
// AC
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

    map<int, int> mp;
    for(int i = 0; i < n; ++i) {
        if (i > 0) cout << " ";
        if (!mp.count(a[i]))
            cout << "-1";
        else {
            cout << mp[a[i]];
        }
        mp[a[i]] = i + 1;
    }
    cout << "\n";

    return 0;
}
