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
    vector<string> words(26);
    words[0] = "a";
    string s = words[0];

    for(int i = 1; i < n; ++i) {
        s += 'a' + i;
        s += words[i - 1];
        words[i] = s;
        if (s.size() >= 1e5) break;
    }

    if(s.size() >= 1e5) {
        s = s.substr(0, 1e5);
    }
    cout << s << "\n";
    return 0;
}
