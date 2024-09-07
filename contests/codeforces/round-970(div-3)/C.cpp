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

        int l, r;
        cin >> l >> r;
        r -= l;
        l = 0;

        int ans = (double)(-1 + sqrt(1 + 8.0 * r)) / 2.0;
        cout << ans + 1 << "\n";
    }
    
    return 0;
}


/*

1

[5,1,5]
*/

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = accumulate(chalk.begin(), chalk.end(), 0ll);
        k %= sum;
        for(int i = 0; i < chalk.size(); ++i) {
            if (chalk[i] > k)
                return i;
            k -= chalk[i];
        }
        return 0;
    }
};