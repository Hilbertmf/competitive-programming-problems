#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

/*
TODO: consider that all strings have fixed size m

*/

int32_t main() {
    FASTIO;
    int t;
    cin >> t;
    
    while(t--){

        int n, m;
        cin >> n >> m;
        vector<string> strs(n);
        string s;
        for(int i = 0; i < n; ++i) {
            cin >> strs[i];
            s += strs[i];
        }

        int ans = 0;
        string str = "narek";
        set<char> st(str.begin(), str.end());
        int pts = 0;
        for(int i = 0, j = 0; i < s.size(); ++i) {
            if (s[i] == str[j]) {
                j++;
                if (j == 5)
                    pts += 5;
                j %= 5;
            }
            else if (st.find(s[i]) != st.end()) {
                pts--;
            }

            if (pts <= -4) {
                pts = 0;
                j = 0;
            }

            ans = max(ans, pts);
        }


        cout << ans << "\n";
    }
    
    return 0;
}
