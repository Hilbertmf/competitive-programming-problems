#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

set<int> getFactors(int n) {
    set<int> fac;
    fac.insert(1);
    for(int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            fac.insert(i);
            fac.insert(n / i);
        }
    }

    fac.insert(n);
    return fac;
}

int32_t main() {
    FASTIO;

    int a, b;
    cin >> a >> b;

    if (a - 1 == b) {
        cout << 1 << "\n";
    }
    else {

        set<int> factors = getFactors(a);
        int ans;

        for(auto &f : factors) {
            if ((a / f) - (b / f) > 1) continue;
            ans = f;
            break;
        }

        cout << ans << "\n";
    }


    return 0;
}
