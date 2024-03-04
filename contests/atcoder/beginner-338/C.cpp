#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

int getMaxAns(vector<int>& grams, vector<int>& nums1,
vector<int>& nums2, int max_, int ans) {
    int n = nums1.size();
    while (max_ >= 0) {
        int curr = INF;
        for(int i = 0; i < n; ++i) {
            if(nums1[i] == 0)
                continue;

            int curr_grams = grams[i] - nums2[i] * max_;
            curr = min(curr, curr_grams / nums1[i]);
        }
        if(curr == INF) continue;
        ans = max(ans, max_ + curr);
        max_--;
    }

    return ans;
}

int32_t main() {
    FASTIO;

    int n;
    cin >> n;

    vector<int> grams(n);
    vector<int> a(n);
    vector<int> b(n);
    for(int i = 0; i < n; ++i)
        cin >> grams[i];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < n; ++i)
        cin >> b[i];

    int max_quotient_a = INF;
    int num_zeros = 0;
    int a_sum = INF;
    int b_sum = INF;
    int ans = 0;

    for(int i = 0; i < n; ++i) {
        if(a[i] == 0 && b[i] == 0) {
            num_zeros += 2;
            continue;
        }
        else if(a[i] == 0) {
            num_zeros++;
            b_sum = min(b_sum, grams[i] / b[i]);
            continue;
        }
        else if(b[i] == 0) {
            num_zeros++;
            a_sum = min(a_sum, grams[i] / a[i]);
            continue;
        }
        
        max_quotient_a = min(max_quotient_a, grams[i] / a[i]);
    }

    if(max_quotient_a == INF) max_quotient_a = 0;

    ans = getMaxAns(grams, b, a, max_quotient_a, ans);
        
    if(a_sum == INF) a_sum = 0;
    if(b_sum == INF) b_sum = 0;
    
    if(ans != INF && num_zeros < n) {
        cout << ans << "\n";
    }
    else {
        cout << a_sum + b_sum << "\n";
    }

    return 0;
}
