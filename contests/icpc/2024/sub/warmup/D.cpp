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

    int d, c, r;
    cin >> d >> c >> r;
    vector<int> can(c);
    vector<int> rev(r);
    for(auto &act : can) cin >> act;
    for(auto &act : rev) cin >> act;
    
    int i = 0, j = 0;
    int act = 0;
    while (i < c || j < r) {        
        if (i < c && d < can[i] && j >= r) break;
        
        if(i < c && d >= can[i]) {
            d -= can[i];
            i++;
        }
        else {
            d += rev[j];
            j++;
        }
        act++;
    }

    cout << act << "\n";
    
    return 0;
}
