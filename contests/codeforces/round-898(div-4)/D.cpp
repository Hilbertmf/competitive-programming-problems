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

        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for(int &num : arr) {
            char c;
            cin >> c;
            if(c == 'B') {
                num = 0;
            }
            else {
                num = 1;
            }
        }

        int op = 0;
        for(int i = 0; i < n; ++i) {
            if(arr[i] == 0) {
                op++;
                i += k - 1;
            }
        }

        cout << op << "\n";

    }
    
    return 0;
}
