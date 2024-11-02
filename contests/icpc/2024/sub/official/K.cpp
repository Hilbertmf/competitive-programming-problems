// WA
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
    int n;
    cin >> n;
    vector<int> nums(n);
    for(auto &num : nums) cin >> num;
    sort(nums.begin(), nums.end());

    int sum = accumulate(nums.begin(), nums.end(), 0);

    bool pos = sum % 2 == 0;
    int target = sum / 2;

    if (!pos) {
        cout << "-1\n";
        return 0;
    }

    vector<int> dp(target + 1, false);
    vector<int> par(target + 1, -1);
    dp[0] = true;

    for(int i = 0; i < n; ++i) {
        for(int j = target; j >= nums[i]; --j) {
            if (dp[j - nums[i]]) {
                dp[j] = true;
                par[j] = i;
            }
        }
    }

    if (dp[target] == false) {
        cout << "-1\n";
        return 0;
    }

    sum = target;
    vector<int> set1;
    vector<int> set2;
    set<int> indices;
    while (sum) {
        int idx = par[sum];
        set1.push_back(nums[idx]);
        sum -= nums[idx];
        indices.insert(idx);
    }

    for(int i = 0; i < n; ++i) {
        if (indices.find(i) == indices.end())
            set2.push_back(nums[i]);
    }

    sort(set1.begin(), set1.end());
    sort(set2.rbegin(), set2.rend());
    int s1 = accumulate(set1.begin(), set1.end(), 0);
    int s2 = accumulate(set2.begin(), set2.end(), 0);

    if (s1 != target || s2 != target) {
        cout << "-1\n";
        return 0;
    }

    int l1 = 0, l2 = 0, suma = 0, sumb = 0;
    vector<int> ans;
    
    while (l1 < set1.size() || l2 < set2.size()) {
        if (suma <= sumb) {
            if (l1 < set1.size()) {
                suma += set1[l1];
                ans.push_back(set1[l1]);
                l1++;
            } else {
                sumb += set2[l2];
                ans.push_back(set2[l2]);
                l2++;
            }
        } else {
            if (l2 < set2.size()) {
                sumb += set2[l2];
                ans.push_back(set2[l2]);
                l2++;
            } else {
                suma += set1[l1];
                ans.push_back(set1[l1]);
                l1++;
            }
        }
    }
    for(int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    
    return 0;
}
