#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// #define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

int32_t main() {
    FASTIO;
    int t;
    cin >> t;
    
    while(t--){

        int n, k;
        cin >> n >> k;
        vector<int> lens(k);
        for(int i = 0; i < k; ++i) {
            cin >> lens[i];
        }

        int op = 0;
        multiset<int> nums(lens.begin(), lens.end());
        while (nums.size() > 1) {
            int sm = *nums.begin();
            int gt = *nums.rbegin();
            nums.erase(nums.begin());
            op += (sm - 1) * 2 + 1;
            nums.erase(nums.find(gt));
            nums.insert(gt + sm);
        }

        cout << op << "\n";
    }
    
    return 0;
}
