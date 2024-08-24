// verdict: WA
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
    
    
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i) cin >> arr[i];

    vector<int> a = arr;
    for(int i = 0; i < n - 2; ++i) {
        a.push_back(arr[i]);
    }

    int subarrs = 0;
    unordered_map<int, int> count;
    count.reserve(a.size());
    count[0] = 1;
    int sum = 0;

    int j = 0;
    for(int i = 0; i < a.size(); ++i) {

        
        int num = a[i];
        sum += num;
        sum %= m;
        if (sum < 0)
            sum += m;


        // if (i >= n - 1) {
        //     sum -= a[j];
        //     if (sum < 0) sum += m;
        //     sum %= m;
        //     ++j;
        // }

        subarrs += count[sum];
        count[sum]++;

    }

    cout << subarrs << "\n";
    
    return 0;
}


class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int subarrs = 0;
        unordered_map<int, int> count;
        count[0] = 1;
        int sum = 0;
        for(int num : nums) {
            sum += num;
            sum %= k;
            if (sum < 0)
                sum += k;
            subarrs += count[sum];
            count[sum]++;
        }

        return subarrs;
    }
};
