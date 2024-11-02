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
    int t;
    cin >> t;
    
    while(t--){

        int n;
        cin >> n;
        vector<int> s(2*n);
        for(int i = 0; i < 2*n; ++i) {
            cin >> s[i];
        }

        int mn = INF, mx = 0;


        int on = count(s.begin(), s.end(), 1);
        if(on % 2 == 0) {
            mn = 0;
        }
        else {
            mn = 1;
        }

        mx = on;
        if (on > n) {
            mx = n - abs(n - on);
        }

        if (on == 0) {
            mn = mx = 0;
        }

        cout << mn << " " << mx << "\n";
    }
    
    return 0;
}
