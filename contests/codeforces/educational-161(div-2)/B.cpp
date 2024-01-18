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
        vector<int> sticks(n);
        for(auto &stick : sticks) cin >> stick;
        
        sort(sticks.begin(), sticks.end());

        int ans = 0;
        map<int, int> count;
        for(int i = 0; i < n; ++i) {
            if(count[sticks[i]] > 0 && i >= 2) {
                
                int repetitions = count[sticks[i]];
                int elems_before = lower_bound(sticks.begin(), sticks.begin() + i, sticks[i]) - sticks.begin();
                
                ans += repetitions * elems_before;
                if(repetitions > 1)
                    ans += (repetitions * (repetitions - 1)) / 2;
            }
            count[sticks[i]]++;
        }

        cout << ans << "\n";

    }
    
    return 0;
}
