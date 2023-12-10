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

    int M, D;
    int y, m, d;
    cin >> M >> D;
    cin >> y >> m >> d;

    if(d == D) {
        if(m == M) {
            y++;
            m = 1;
        }
        else {
            m++;
        }
        d = 1;
    }
    else {
        d++;
    }

    cout << y << " " << m << " " << d << "\n";

    return 0;
}
