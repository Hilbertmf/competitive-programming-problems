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

        int n, k, x;
        cin >> n >> k >> x;
        vector<int> nums(n);
        for(int i = 0; i < n; ++i) cin >> nums[i];
        
        sort(nums.begin(), nums.end(), greater<int>());

        int sum = accumulate(nums.begin(), nums.end(), 0ll);
        int curr_k = 0;
        int removed_nums = 0;

        int bob_idx = 0;
        for(bob_idx = 0; bob_idx < n && bob_idx < x; ++bob_idx) {
            if(nums[bob_idx] < 0) break;
            removed_nums += nums[bob_idx];
        }
                
        bob_idx--;
        
        int res = sum - (2 * removed_nums);
        int ans = res;
        
        int left = 0, right = bob_idx;
        while (left < k) {
            sum -= nums[left];
            removed_nums -= nums[left];

            if(right < n - 1 && nums[right + 1] > 0) {
                right++;
                removed_nums += nums[right];
            }

            res = sum - (2 * removed_nums);
            ans = max(ans, res);
            left++;
        }

        cout << ans << "\n";

    }
    
    return 0;
}
