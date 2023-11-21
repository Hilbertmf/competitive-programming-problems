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
        vector<int> a(n);
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int ops = 0;

        for(int i = n - 2; i >= 0; --i) {
            if(a[i] > a[i + 1]) {
                int k = CEILDIVISION(a[i], a[i+1]);
                ops += k - 1;
                a[i] = floor((double)a[i] / k);
            }

        }

        cout << ops << "\n";
    }
    
    return 0;
}
