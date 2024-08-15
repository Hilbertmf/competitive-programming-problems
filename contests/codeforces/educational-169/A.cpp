#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

bool isAtMid(int x, vector<int>& p) {
    
    for(int i = 0; i < p.size(); ++i) {
        int nxt = INF, prev = INF;
        if (i > 0)
            prev = p[i] - p[i-1];
        if (i != p.size() - 1)
            nxt = p[i + 1] - p[i];
        int dist = min(prev, nxt);

        int cur = abs(x - p[i]);
        if (dist < cur) return false;
    }
    return true;
}

int32_t main() {
    FASTIO;
    int t;
    cin >> t;
    
    while(t--){

        int n;
        cin >> n;
        vector<int> p(n);
        for(int i = 0; i < n; ++i) {
            cin >> p[i];
        }
        set<int> vis(p.begin(), p.end());
        sort(p.begin(), p.end());

        int ans = -1;
        for(int i = p[0] + 1; i <= p.back() - 1 && n % 2 == 0; ++i) {
            if (vis.count(i) != 0) continue;

            if (isAtMid(i, p)) {
                ans = i; break;
            }
        }


        bool pos = ans != -1;
        if(pos) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    
    return 0;
}
