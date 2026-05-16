// AC
// https://codeforces.com/problemset/problem/677/A
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
    int n, h;
    cin >> n >> h;

    vector<int> a(n);
    int res = 0;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] > h) res +=2;
        else res++;
    }

    cout << res << "\n";
    
    return 0;
}
