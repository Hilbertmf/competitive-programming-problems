// AC
// https://codeforces.com/problemset/problem/313/B
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

    string s;
    cin >> s;
    int n = s.size(), m;

    vector<int> p1(n), p2(n);

    for(int i = 0; i < n; ++i) {
        if (s[i] == '.' && i != n -1 && s[i + 1] == '.') {
            p1[i] = 1;
        } else if (s[i] == '#' && i != n -1 && s[i + 1] == '#') {
            p2[i] = 1;
        }
    }

    for(int i = 1; i < n; ++i) {
        p1[i] += p1[i - 1];
        p2[i] += p2[i - 1];
    }

    cin >> m;
    for(int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;

        int res = 0;
        l--;
        r--;
        if(l > 0) {
            res += p1[r] - p1[l - 1];
            // DEBUG(res);
            res += p2[r] - p2[l - 1];
        }
        else {
            res += p1[r];
            // DEBUG(res);
            res += p2[r];

            // DEBUG(p2[r]);
        }

        if (r != n - 1 && s[r + 1] == s[r]) res--;

        cout << res << "\n";
    }



    return 0;
}
