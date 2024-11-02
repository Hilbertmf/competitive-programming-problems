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
    int t, tcase = 1;
    cin >> t;

    
    while(t--){

        int n, k;
        cin >> n >> k;
        vector<int> s(n);
        for(int i = 0; i < n; ++i) cin >> s[i];
        sort(s.begin(), s.end());
        int time = s[0];
        for(int i = 2; i < n; ++i) {
            time += s[0] * 2;
        }

        cout << "Case #" << tcase << ": ";
        if(time <= k) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
        tcase++;
    }
    
    return 0;
}
