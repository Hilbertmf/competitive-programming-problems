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

        int n, m;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        for(int i = 0; i < n; ++i) cin >> b[i];
        cin >> m;
        vector<int> d(m);
        for(int i = 0; i < m; ++i) cin >> d[i];

        set<int> b_set(b.begin(), b.end());
        bool ans = true;

        if (b_set.find(d.back()) == b_set.end())
            ans = false;

        multiset<int> d_set(d.begin(), d.end());

        for(int i = 0; i < n && ans; ++i) {
            if (a[i] != b[i]) {
                if (d_set.find(b[i]) == d_set.end())
                    ans = false;
                else
                    d_set.erase(d_set.find(b[i]));
            }
        }

        if(ans) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }

    }
    
    return 0;
}
