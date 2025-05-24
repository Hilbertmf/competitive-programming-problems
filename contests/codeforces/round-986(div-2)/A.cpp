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
    int t, loops = 0;
    cin >> t;
    
    while(t--){

        bool ok = false;
        int n, a, b;
        cin >> n >> a >> b;
        string s;
        cin >> s;

        pair<int, int> pos = {0, 0};
        set<pair<int, int>> seen_at_start;
        seen_at_start.insert(pos);
        for(int i = 0; i < 1000 && !ok && loops < 1e7; ++i) {
            for(auto &c : s) {
                if(c == 'N') {
                    pos.second++;
                }
                else if(c == 'E') {
                    pos.first++;
                }
                else if(c == 'S') {
                    pos.second--;
                }
                else {
                    pos.first--;
                }

                if (pos.first == a && pos.second == b) {
                    ok = true; break;
                }

                loops++;
            }

            if (seen_at_start.count(pos)) break;
            seen_at_start.insert(pos);
        }


        if(ok) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    
    return 0;
}
