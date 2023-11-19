// acc
#include <bits/stdc++.h> 
using namespace std; 
#define DEBUG(x) cout << #x << " >>>> " << x << endl 
#define MID(l, r) (l + (r - l) / 2) 
#define CEILDIVISION(x, y) ((x + y - 1) / y) 
#define INF (int)1e9 
#define LONGINF (long long)1e18 
#define MEM(arr, val) memset(arr, (val), sizeof(arr)) 
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
#define int long long 
const int MOD = 1e9 + 7; // 10^9 + 7 
 
int32_t main() { 
    FASTIO;

    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    vector<int> num0s(2);
    int num1s = 0;

    int x = 0;
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        if(nums[i] == 0) {
            ans += num0s[x^1];
            num0s[x]++;
        }
        else {
            num1s++;
            ans += num0s[x];
            x ^= 1;
        }
        ans += num1s / 2;
        if(num1s % 2 == 1) ans++;
    }

        cout << ans << "\n";

    return 0; 
}
