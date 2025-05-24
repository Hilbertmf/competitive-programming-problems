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

        int k;
        cin >> k;
        vector<int> nums(k);
        for(int i = 0; i < k; ++i) {
            cin >> nums[i];
        }

        multiset<int> m(nums.begin(), nums.end());
        pair<int, int> ans = {-1, -1};

        bool ok = false;
        for(auto &num : nums) {
            
            m.erase(m.find(num));
            if ((k - 2) % num == 0 && m.count((k - 2) / num)) {
                ans = {num, (k - 2) / num};
                ok = true;
                break;
            }
            if (ok) break;
            m.insert(num);
        }


        cout << ans.first << " " << ans.second << "\n";


    }
    
    return 0;
}
