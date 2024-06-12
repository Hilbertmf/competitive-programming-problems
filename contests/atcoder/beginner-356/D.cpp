#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 998244353;

int main() {
    FASTIO;
    
    int n, m;
    cin >> n >> m;

    int sum = 0;
    for(int i = 0; i <= n; ++i) {
        sum += __builtin_popcount(i & m) % MOD;
    }

    cout << sum % MOD << "\n";
    return 0;
}
