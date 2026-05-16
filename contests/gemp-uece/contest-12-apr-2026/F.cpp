// AC
// https://codeforces.com/problemset/problem/433/B
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
    vector<int> a(n), sorted(n), p2(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        p2[i] = a[i];
    }

    sorted = a;
    sort(sorted.begin(), sorted.end());
    vector<int> p(n);
    p = sorted;
    p2[0] = a[0];
    for(int i = 1; i < n; ++i) {
        p[i] += p[i - 1];
        p2[i] += p2[i - 1];

    }

    int m;
    cin >> m;
    while (m--) {
        int l, r, t;
        cin >> t >> l >> r;

        l--; r--;

        if(t == 1) {
            if (l == 0)
                cout << p2[r] << "\n";
            else 
                cout << p2[r] - p2[l -1] << "\n";
        }
        else {
            if (l == 0)
                cout << p[r] << "\n";
            else 
                cout << p[r] - p[l -1] << "\n";
        }
    }


    return 0;
}
