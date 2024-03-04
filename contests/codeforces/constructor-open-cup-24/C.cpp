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
        vector<int> arr(n);
        int max_sum = 0;
        for(int i = 0; i < n; ++i) {
            cin >> arr[i];
            max_sum += arr[i];
        }

        if(n > 2) {
            cout << max_sum << "\n";
        }
        else {
            if(arr[1] > 0) {
                cout << arr[0] + 1 << "\n";
            }
            else {
                cout << arr[0] << "\n";
                
            }
        }

    }
    
    return 0;
}
