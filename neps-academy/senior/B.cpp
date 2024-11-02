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

    string s, t;
    cin >> s >> t;

    int count = 0;
    for(int i = 0; i < s.size(); ++i) {
        if (s[i] == t[0]) {
            int count_equals = 0;
            for(int j = 0; j < t.size() && i + j < s.size(); ++j) {
                count_equals += s[i + j] == t[j];
            }
            count += count_equals == t.size();
        }
    }
    cout << count << "\n";

    return 0;
}
