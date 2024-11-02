// https://codeforces.com/contest/2036/problem/A
// AC
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
        bool ok = true;
        int last;
        for(int i = 0; i < n; ++i) {
            int cur;
            cin >> cur;
            if (i != 0 && abs(cur - last) != 5 && abs(cur - last) != 7) {
                ok = false;
            }
            last = cur;
        }

        if(ok) {
            cout << "YES" << "\n";
        }
        else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}
