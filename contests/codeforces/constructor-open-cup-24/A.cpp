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

        int n, l, r, k;
        cin >> n >> l >> r >> k;
        vector<int> times(n + 1);
        for(int i = 1; i <= n; ++i) cin >> times[i];
        
        int time = 0;
        bool drinks = l <= k && k <= r;

        int heating;

        if(!drinks) {
            if(k < l)
                heating = 1;
            else
                heating = 0;
        }
                
        int curr = 0;
        for(int i = 1; i <= n && ! drinks; ++i) {
            if(heating) {
                k += times[i] - times[i - 1];
            }
            else {
                k -= times[i] - times[i - 1];
            }

            curr += times[i] - times[i - 1];

            if (l <= k && k <= r) {
                drinks = true;
                time = curr;
            }
            else {
                if(k < l)
                    heating = 1;
                else
                    heating = 0;
            }

        }


        if(drinks) {
            cout << time << "\n";
        }
        else {
            cout << -1 << "\n";
            
        }

    }
    
    return 0;
}
