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

        int n, f, k;
        cin >> n >> f >> k;
        vector<int> vals(n);
        for(int i = 0; i < n; ++i) {
            cin >> vals[i];
        }

        int fav = vals[f - 1];
        sort(vals.rbegin(), vals.rend());

        int i = k;
        bool can_find_fav = false;
        bool maybe = false;
        int idx = i;

        for(; i < n && !can_find_fav; ++i) {
            if (vals[i] == fav)
                can_find_fav = true;
        }

        for(int j = idx - 1; j >= 0; --j) {
            if (vals[j] == fav)
                maybe = true;
        }

        if(can_find_fav && maybe) {
            cout << "MAYBE" << "\n";
        }
        else if (can_find_fav) // not removed
            cout << "NO" << "\n";
        else {
            cout << "YES" << "\n";
        }

    }
    
    return 0;
}
