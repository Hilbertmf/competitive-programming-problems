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

    int n, q, t, l = 1, r = 2;
    cin >> n >> q;

    int ans = 0;

    while (q--) {
        char h;
        cin >> h >> t;


        if(h == 'R') {
            if (t == r) {}
            else if(l < r) {
                if(l < t && r > t) {
                    ans += abs(r - t);
                }
                else {
                    if(t > r) {
                        ans += abs(t - r);
                    }
                    else {
                        ans += n - r;
                        ans += t;
                    }
                }
            }
            else {
                if(r < t && t < l) {
                    ans += abs(t - r);
                }
                else {
                    if(t < r) {
                        ans += abs(r - t);
                    }
                    else {
                        ans += r;
                        ans += n - t;
                    }
                }
            }
            r = t;
        }
        else {
            if (t == l) {}
            else if (l < r) {
                if(l < t && r > t) {
                    ans += abs(t - l);
                }
                else {
                    if(t < l) {
                        ans += abs(l - t);
                    }
                    else {
                        ans += l;
                        ans += n - t;
                    }
                }
            }
            else {
                if(r < t && l > t) {
                    ans += abs(l - t);
                }
                else {
                    if(t > l) {
                        ans += abs(t - l);
                    }
                    else {
                        ans += n - l;
                        ans += t;
                    }
                }
            }
            l = t;
        }

    }

    cout << ans << "\n";

    return 0;
}
