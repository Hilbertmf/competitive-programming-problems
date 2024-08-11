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

        int xc, yc, k;
        cin >> xc >> yc >> k;

        if(k % 2 == 0) {
            int acc = 1;
            for(int i = 0; i < k; i += 2, ++acc) {
                cout << xc + acc << " " << yc + acc << "\n";
                cout << xc - acc << " " << yc - acc << "\n";
            }
        }
        else {
            int acc = 1;
            cout << xc << " " << yc << "\n";
            for(int i = 0; i < k / 2; ++i, ++acc) {
                cout << xc + acc << " " << yc + acc << "\n";
                cout << xc - acc << " " << yc - acc << "\n";
            }
        }


    }
    
    return 0;
}
