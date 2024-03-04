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
        int sum = 0;
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
            sum += a[i];
        }

        if(sum % 3 == 0) {
            cout << 0 << "\n";
        }
        else {
            if((sum + 1) % 3 == 0) {
                cout << 1 << "\n";
            }
            else if((sum + 2) % 3 == 0) {
                bool mod1 = false;
                for(int i = 0; i < n; ++i) {
                    if(a[i] % 3 == 1) {
                        mod1 = true; break;
                    }
                }
                
                if(mod1) {
                    cout << 1 << "\n";
                }
                else {
                    cout << 2 << "\n";
                }

            }
        }

    }
    
    return 0;
}
