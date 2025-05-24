#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
#define eps 1e-9
const int MOD = 1e9 + 7; // 10^9 + 7

int32_t main() {
    FASTIO;

    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    long double ratio = (long double)nums[1] / nums[0];
    bool flag = true;

    for(int i = 0; i < n - 2; ++i) {
        if (nums[i + 1] * nums[i + 1] != nums[i] * nums[i + 2]) {
            flag = false; break;
        }
    }

    if(flag) {
        cout << "Yes\n";
    }
    else {
        cout << "No\n";
    }


    return 0;
}
