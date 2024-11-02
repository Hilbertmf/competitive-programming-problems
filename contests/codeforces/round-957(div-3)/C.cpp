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

        int n, m, k;
        cin >> n >> m >> k;
        vector<int> perm;
        set<int> nums;
        for(int i = 1; i <= n; ++i) {
            nums.insert(i);
        }

        while (!nums.empty()) {
            if (*nums.rbegin() >= k ||
                *nums.rbegin() > m) {
                int gt = *nums.rbegin();
                perm.push_back(gt);
                nums.erase(gt);
            }
            else {
                perm.push_back(*nums.begin());
                nums.erase(nums.begin());
            }
        }

        for(int i = 0; i < n; ++i) {
            if (i > 0) cout << " ";
            cout << perm[i];
        }
        cout << "\n";
    }
    
    return 0;
}
