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
        vector<int> nums(n);
        for(auto &num : nums) cin >> num;
        
        unordered_map<int, int> freq;
        unordered_map<int, deque<int>> indices;
        int ans = k;
        bool possible = false;

        for(int i = 0; i < n; ++i) {
            freq[nums[i]]++;
            if(freq[nums[i]] >= k)
                possible = true;

            indices[nums[i]].push_back(i);
            if(indices[nums[i]].size() == k) {

                int start = indices[nums[i]].front();
                int nums_to_remove = i - start + 1 - k;
                
                ans = min(ans, nums_to_remove);

                if (k > 1) {

                    indices[nums[i]].pop_back();
                    
                    int curr = i;
                    int end = indices[nums[i]].back();

                    // DEBUG(curr);
                    // DEBUG(end);
                    
                    // DEBUG(curr - end - 1);
                    // DEBUG(1 + start);

                    if(curr - end > start - curr)
                        ans = min(ans, 1 + (end + 1 - k + 1));
                    indices[nums[i]].push_back(i);
                }

                indices[nums[i]].pop_front();
            }

        }

        if(possible) {
            cout << ans << "\n";
        }
        else {
            cout << -1 << "\n";
        }
    }
    
    return 0;
}
