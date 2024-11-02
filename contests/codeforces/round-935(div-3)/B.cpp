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

        int a, b, m;
        cin >> a >> b >> m;

        long long ans = 0;

        
        long long start = 0;
        long long end = m;
        long long f1 = (m / a) + 1;
        long long f2 = (m / b) + 1;


        cout << f1 + f2 << "\n";
    }
    
    return 0;
}
