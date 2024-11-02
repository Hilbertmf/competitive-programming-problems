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
    vector<vector<int>> a(n + 1, vector<int>(n + 1));
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= i; ++j) {
            cin >> a[i][j];
        }
    }

    int elem = 1;
    for(int i = 1; i <= n; ++i) {
        if(elem >= i) {
            elem = a[elem][i];
        }
        else {
            elem = a[i][elem];
        }
    }

    cout << elem << "\n";

    return 0;
}
