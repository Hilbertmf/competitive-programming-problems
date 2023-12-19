// https://codeforces.com/contest/1914/problem/B
// accepted
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

        int n, k;
        cin >> n >> k;
        vector<int> ans(n);
        
        if(k == 0) {
            int tmp = n;
            for(int i = 0; i < n; ++i, --tmp) {
                ans[i] = tmp;
            }
        }
        else {
            
            vector<int> diff(n+1);
            for(int i = 1; i <= n; ++i) {
                diff[i] = i;
            }

            int last;
            for(int i = n - 1, j = 0; i >= 0 && j < k; --i, ++j) {
                ans[i] = (i+1);
                if(j == k - 1)
                    last = ans[i];
            }

            last--;
            for(int i = 0; i < n - k; ++i, --last) {
                ans[i] = last;
            }

        }

        for(int i = 0; i < n; ++i) {
            cout << ans[i];
            if(i != n - 1) cout << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
