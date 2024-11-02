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

    bool possible = false;
    for(int w = 1; w < s.size() - 1 && !possible; ++w) {
        for(int c = 0; c < w && !possible; ++c) {
            string tmp;
            for(int i = 0; (i * w) + c < s.size(); ++i) {
                tmp += s[(i * w) + c];
            }
            
            if (tmp.size() == t.size() &&
                tmp == t) {
                possible = true;
                break;
            }
        }
    }

    if(possible) {
        cout << "Yes" << "\n";
    }
    else {
        cout << "No" << "\n";
    }
    return 0;
}
