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

    int l, r, digit;
    cin >> l >> r;
    int ans = 0;

    string s = to_string(l);
    string t = to_string(r);

    // if (s.size() == t.size()) {
    //     digit = s[0] - '0';
    //     while (digit < (t[0] - '0')) {
    //         ans += pow(digit, s.size() - 1);
    //         digit++;
    //     }


    // }

    digit = (s[0] - '0');
    for(int sz = s.size(); sz <= t.size(); ++sz) {
        while (digit <= 9) {
            if (sz == t.size() && digit > (t[0] - '0')) break;
            if (sz == s.size() && digit < (s[0] - '0')) break;
            // if (sz == s.size() && digit == (s[0] - '0')) {

            // }
            ans += pow(digit, sz - 1);
            digit++;
        }
        digit = 1;
    }

    DEBUG(ans);
    digit = s[0] - '0';
    for(int i = 1; i < s.size(); ++i) {
        int cur = s[i] - '0';
        if (cur > digit) cur = digit - 1;
        ans -= cur * (pow(digit, s.size() - i - 1));
    }

    // for(int i = 1; i < t.size(); ++i) {
    //     ans += (t[i] - '0') * (pow(digit, t.size() - i - 1));
    // }


    digit = t[0] - '0';
    for(int i = 1; i < t.size(); ++i) {
        int cur = t[i] - '0';
        if (cur >= digit) cur = digit - 1;
        ans -= max(0ll, (digit - (cur) - 1)) * (pow(digit, t.size() - i - 1));
    }


    cout << ans << "\n";

    return 0;
}
