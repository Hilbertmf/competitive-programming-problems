// https://codeforces.com/contest/1914/problem/D
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

        int ans = 0;
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        vector<int> c(n);
        for(auto &item : a) cin >> item;
        for(auto &item : b) cin >> item;
        for(auto &item : c) cin >> item;
        multiset<pair<int, int>> set_a;
        multiset<pair<int, int>> set_b;
        multiset<pair<int, int>> set_c;
        for(int i = 0; i < n; ++i) set_a.insert({a[i], i});
        for(int i = 0; i < n; ++i) set_b.insert({b[i], i});
        for(int i = 0; i < n; ++i) set_c.insert({c[i], i});

        for(int i = 0; i < n; ++i) {
            
            int bi = b[i];
            set_b.erase(set_b.find({bi, i}));
            int ci = c[i];
            set_c.erase(set_c.find({ci, i}));

            int curr = a[i];
            if(set_b.rbegin()->second == set_c.rbegin()->second) {
                curr += max(set_b.rbegin()->first + next(set_c.rbegin())->first,
                    next(set_b.rbegin())->first + set_c.rbegin()->first
                );
            }
            else {
                curr += set_b.rbegin()->first + set_c.rbegin()->first;
            }

            ans = max(ans, curr);

            set_b.insert({bi, i});
            set_c.insert({ci, i});

        }
        
        cout << ans << "\n";

    }
    
    return 0;
}
