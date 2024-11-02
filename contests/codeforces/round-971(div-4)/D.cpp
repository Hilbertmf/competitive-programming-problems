#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

/*

for every vertical line connected by (x,y1) and (x, y2):
    there is a right tri for every point that is at the x line of x1 and x2
    so tri += pts_at_row[x1] - 1 + pts_at_row[x2] - 1;

    given two pts at same y: (x1, y), (x2, y)
    well have a right tri if: x3 = MID(x1, x2) and if (x2 - x1 + 1) is odd


resumindo:
pra cada par c/ x igual: tri += n - 2
pra cada par c/ y igual: if ODD(x2 - x1 + 1) and there is  and if (x2 - x1 + 1) is odd tri++
*/

int32_t main() {
    FASTIO;
    int t;
    cin >> t;
    
    while(t--){

        int n;
        cin >> n;
        vector<pair<int, int>> pts(n);
        map<int, int> count_by_x;
        set<pair<int, int>> set_pt;
        for(int i = 0; i < n; ++i) {
            int x, y;
            cin >> x >> y;
            pts[i] = {x, y};
            count_by_x[x]++;
            set_pt.insert({x, y});
        }

        int ans = 0;
        for(auto &[x, occ] : count_by_x) {
            if (occ > 1) {
                ans += n - 2;
            }
        }

        for(int i = 0; i < n; ++i) {
            int x = pts[i].first, y = pts[i].second;
            int target_y = y ^ 1;
            pair<int, int> p1 = {x - 1, target_y};
            pair<int, int> p2 = {x + 1, target_y};
            if (set_pt.count(p1) && set_pt.count(p2)) {
                ans++;
            }
        }

        cout << ans << "\n";
    }
    
    return 0;
}
