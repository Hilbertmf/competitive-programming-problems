// https://atcoder.jp/contests/abc328/tasks/abc328_c
// accepted
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
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    vector<bool> equal_adj(n);

    for(int i = 0; i < s.size() - 1; ++i) {
        equal_adj[i] = s[i] == s[i+1];
    }

    vector<int> prefix_sum(n);
    prefix_sum[0] = equal_adj[0];

    for(int i = 1; i < equal_adj.size(); ++i) {
        prefix_sum[i] = equal_adj[i] + prefix_sum[i-1];
    }

    while (q--) {
        int ans = 0, l, r;
        cin >> l >> r;
        l--;
        r--;

        if(l == r) {
            cout << 0 << "\n";
        }
        else {

            ans = prefix_sum[r - 1];
            if(l > 0) 
                ans -= prefix_sum[l-1];

            cout << ans << "\n";
            
        }
    }


    return 0; 
}
