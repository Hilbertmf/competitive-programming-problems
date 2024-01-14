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
        vector<int> greater_than;
        vector<int> less_than;
        vector<int> different;

        for(int i = 0; i < n; ++i) {
            int op, x;
            cin >> op >> x;
            if(op == 1) { // >=
                greater_than.push_back(x);
            }
            else if(op == 2) { // <= 
                less_than.push_back(x);
            }
            else { // !=
                different.push_back(x);
            }
        }

        int low = *max_element(greater_than.begin(), greater_than.end());
        int high = *min_element(less_than.begin(), less_than.end());
        sort(different.begin(), different.end());

        int ans = high - low + 1;
        for(int i = 0; i < different.size() && ans > 0; ++i) {
            if(different[i] >= low && different[i] <= high)
                ans = max(ans - 1, 0ll);
            if(ans <= 0) break;
        }

        cout << max(ans, 0ll) << "\n";
    }
    
    return 0;
}
