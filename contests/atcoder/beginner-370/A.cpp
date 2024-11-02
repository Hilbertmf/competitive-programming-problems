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

    int l, r;
    cin >> l >> r;
    if (!(l == 1 && r == 1) && (l == 1 || r == 1)) {
        if(l == 1)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    else
        cout << "Invalid\n";
    return 0;
}
