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
        for(int i = 0; i < n; ++i) cin >> a[i];

        map<int, int> prefix_idx;
        prefix_idx[0] = -1;
        int sum = 0, count = 0, last_end = -1;

        for(int i = 0; i < n; ++i) {
            sum += a[i];
            if (prefix_idx.count(sum)) {
                int start = prefix_idx[sum] + 1;
                if (start > last_end) {
                    count++;
                    last_end = i;
                }
            }
            prefix_idx[sum] = i;
        }

        cout << count << "\n";
    }
    
    return 0;
}

