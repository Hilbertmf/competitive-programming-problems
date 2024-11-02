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
        cin >> n >> m;
        string s, c;
        cin >> s;
        vector<int> ind(m);
        for(int i = 0; i < m; ++i) {
            cin >> ind[i];
            ind[i]--;
        }
        cin >> c;

        sort(ind.begin(), ind.end());
        ind.erase(unique(ind.begin(), ind.end()), ind.end());
        sort(c.begin(), c.end());
        for(int i = 0; i < ind.size(); ++i) {
            s[ind[i]] = c[i];
        }

        cout << s << "\n";
    }
    
    return 0;
}

