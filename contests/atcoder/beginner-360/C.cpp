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

    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> w(n);
    vector<vector<pair<int, int>>> box_pos(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i]--;
    }
    for(int i = 0; i < n; ++i) {
        cin >> w[i];
    }

    
    for(int i = 0; i < n; ++i) {
        box_pos[a[i]].push_back({w[i], i});
    }

    int ans = 0;
    for(int i = 0; i < n; ++i) {
        if (box_pos[i].size() > 1) {
            sort(box_pos[i].begin(), box_pos[i].end());
            
            for(int j = 0; j < box_pos[i].size() - 1; ++j) {
                ans += box_pos[i][j].first;
            }
        }
    }


    cout << ans << "\n";
    return 0;
}
