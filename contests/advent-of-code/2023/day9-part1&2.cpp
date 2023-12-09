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

    string in;
    int ans = 0;

    while (getline(cin, in)) {
        
        vector<int> nums;
        stringstream ss(in);
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }

        // for part2 uncomment this line
        // reverse(nums.begin(), nums.end());

        int i = nums.size() - 1;
        
        vector<int> sol;
        sol.push_back(nums.back());
        while (nums.size() > 0) {
            for(int i = 0; i < nums.size() - 1; ++i) {
                nums[i] = nums[i + 1] - nums[i];
            }
            nums.resize(nums.size() - 1);
            sol.push_back(nums.back());

            bool all_zero = true;

            for(auto &n : nums) {
                if(n != 0) {
                    all_zero = false;
                    break;
                }
            }

            if(all_zero) break;

        }

        ans += accumulate(sol.begin(), sol.end(), 0);

    }

    cout << ans << "\n";

    return 0;
}