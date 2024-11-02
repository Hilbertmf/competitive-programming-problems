#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define INF_DOUBLE numeric_limits<long double>::max()
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

bool is_valid_number(const string& s) {
    for (char c : s) {
        if (c < '0' || c > '9') return false;
    }
    return true;
}

int32_t main() {
    FASTIO;
    int t, tcase = 1;
    cin >> t;

    while(t--){
        int a, b, m, ans = 0;
        cin >> a >> b >> m;

        string s_a = to_string(a);
        string s_b = to_string(b);

        vector<string> peaks;
        int sz = s_a.size();
        if (sz % 2 == 0) sz++;

        if (sz <= s_b.size()) {
            while (sz <= s_b.size()) {
                for(char c = '1'; c <= '9'; ++c) {
                    if (((int)(c - '0') + (sz / 2)) > 9) break;

                    int i;
                    string s;
                    for(i = 0; i < sz / 2; ++i) {
                        s += (char)(c + i);
                    }
                    s += (char)(c + i);
                    i--;
                    for(; i >= 0; --i) {
                        s += (char)(c + i);
                    }

                    peaks.push_back(s);
                }
                sz += 2;
            }
        }

        for(auto &s : peaks) {
            int count_0 = 0;
            for(auto &c : s) if (c == '0') count_0++;
            if (count_0) continue;

            if (!is_valid_number(s)) continue;
            int num = stoll(s);
            if (num < a || num > b) continue;
            if (num % m != 0) continue;
            ans++;
        }

        cout << "Case #" << tcase << ": ";
        cout << ans << "\n";
        tcase++;
    }

    return 0;
}
