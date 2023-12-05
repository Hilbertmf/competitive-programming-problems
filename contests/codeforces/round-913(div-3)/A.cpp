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

        char c;
        int n;
        cin >> c >> n;

        for(int i = 0; i < 8; ++i) {
            if(i + 1 == n) continue;
            cout << c << i+1 << "\n";
        }


        for(int i = 0; i < 8; ++i) {
            char tmp = 'a' + i;
            if(tmp == c) continue;
            cout << tmp << n << "\n";
        }

    }

    return 0;
}
