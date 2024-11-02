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

    vector<int> b, a;
    int l = 0, r = n - 1;
    int sumb = 0;
    while (l < r) {
        b.push_back(nums[r]);
        r--;
        sumb += b.back();
        if (sumb >= sum / 2) break;
        b.push_back(nums[l]);
        sumb += b.back();
        l++;
        if (sumb >= sum / 2) break;
    }

    for(int i = l; i <= r && i < n; ++i) {
        a.push_back(nums[i]);
    }

    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());

    int SUMA = accumulate(a.begin(), a.end(), 0);
    int SUMB = accumulate(b.begin(), b.end(), 0);

    if(SUMA != SUMB) {
        cout << "-1\n";
    }
    else {
        
        int l1 = 0, l2 = 0, suma = 0;
        vector<int> ans;
        sumb = 0;
        while (l1 < a.size() || l2 < b.size()) {
            if (suma <= sumb) {
                suma += a[l1];
                ans.push_back(a[l1]);
                l1++;
            }
            else {
                sumb += b[l2];
                ans.push_back(b[l2]);
                l2++;

            }
        }

        for(int i = 0; i < ans.size(); ++i) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }


    return 0;
}
