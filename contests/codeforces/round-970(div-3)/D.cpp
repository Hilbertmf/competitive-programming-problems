#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7;

int32_t main() {
    FASTIO;
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        vector<int> nums(n + 1);
        for(int i = 1; i <= n; ++i) cin >> nums[i];
        string s; cin >> s;
        
        vector<bool> is_black(n + 1, false);
        for(int i = 0; i < s.size(); ++i) {
            is_black[i + 1] = (s[i] == '0');
        }

        vector<int> vis(n + 1, -1);
        vector<int> f(n + 1, 0);

        for(int i = 1; i <= n; ++i) {
            if (vis[i] != -1) continue;
        
            int cur = i;
            int count = 0;
            set<int> seen;
            
            while (true) {
                seen.insert(cur);
                vis[cur] = i;
                if (is_black[cur])
                    count++;
                cur = nums[cur];
                if (vis[cur] == i) break;
            }
            
        
            for(int node : seen) {
                f[node] = count;
            }
        }
        
        for(int i = 1; i <= n; ++i) {
            cout << f[i] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
