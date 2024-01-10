// https://atcoder.jp/contests/abc334/tasks/abc334_d
// time: O(q * logn)
// space: O(n)
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

    int n, q;
    cin >> n >> q;
    vector<int> costs(n);
    for(int &cost : costs) cin >> cost;
    sort(costs.begin(), costs.end());
    vector<int> prefix(n);
    prefix[0] = costs[0];
    for(int i = 1; i < n; ++i)
        prefix[i] = prefix[i - 1] + costs[i];
    
    
    while (q--) {
        int x;
        cin >> x;

        auto it = lower_bound(prefix.begin(), prefix.end(), x);
        int pos = it - prefix.begin();
        if(*it == x)
            pos++;

        cout << pos << "\n";

    }

    return 0;
}
