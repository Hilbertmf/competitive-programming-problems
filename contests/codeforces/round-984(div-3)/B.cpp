// https://codeforces.com/contest/2036/problem/B
// AC
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

        vector<int> b(k), c(k);
        set<int> brands;
        for(int i = 0; i < k; ++i) {
            cin >> b[i] >> c[i];
            brands.insert(b[i]);
        }

        int ans = 0;


        if(brands.size() <= n) {            
            for(int i = 0; i < k; ++i) {
                ans += c[i];
            }
        }
        else {
            map<int, int> mp;
            for(int i = 0; i < k; ++i) {
                mp[b[i]] += c[i];
            }
            priority_queue<int> heap;
            for(auto &[k, v] : mp) {
                heap.push(v);
            }

            for(int i = 0; i < n; ++i) {
                if (heap.empty()) break;
                ans += heap.top();
                heap.pop();
            }
        }

        cout << ans << "\n";
    }
    
    return 0;
}