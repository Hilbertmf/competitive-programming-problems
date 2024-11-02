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

        int a, b, c;
        cin >> a >> b >> c;
        multiset<int> nums;
        nums.insert(a);
        nums.insert(b);
        nums.insert(c);

        for(int i = 0; i < 5; ++i) {
            int sm = *nums.begin();
            sm++;
            nums.erase(nums.begin());
            nums.insert(sm);
        }

        int ans = 1;
        for(auto &num : nums) {
            ans *= num;
        }
        cout << ans << "\n";
    }
    
    return 0;
}
