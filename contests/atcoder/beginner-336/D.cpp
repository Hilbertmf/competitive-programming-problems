#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

/*
idea: take a look at Longest increasing subsequence (LIS)
        adapt it to Longest increasing subarray (LISarray)
        for every position i we must have: LISarray ending in i and
                                            LDSarray starting at i + 1
        for every i: f(i) = min(LIS(i), LDS(i + 1))

        Li = length of longest non-dec subarr ending at i
        Li = nums[i] can be part of li-1 or not
        include = L(i - 1) + 1
        exclude = nums[i]
        L(i) = min(include, exclude)
        
        Ri = length of longest non-inc subarr starting at i
        Ri = nums[i] can be part of ri-1 or not
        include = R(i - 1) + 1
        exclude = nums[i]
        R(i) = min(include, exclude)

*/

int32_t main() {
    FASTIO;

    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &num : a) cin >> num;
    
    vector<int> left(n);
    vector<int> right(n + 1);

    left[0] = 1;
    for(int i = 1; i < n; ++i) {
        int include = left[i - 1] + 1;
        int exclude = a[i];
        left[i] = min(include, exclude);
    }
    
    right.back() = 0;
    for(int i = n - 1; i >= 0; --i) {
        int include = right[i + 1] + 1;
        int exclude = a[i];
        right[i] = min(include, exclude);
    }

    int ans = 0;

    for(int i = 0; i < n; ++i) {
        int curr = min(left[i], right[i]);
        ans = max(ans, curr);
    }

    cout << ans << "\n";

    return 0;
}
