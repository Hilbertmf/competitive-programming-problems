// TODO solution
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

    int n, m;
    cin >> n >> m;
    vector<int> L(n), R(n);
    vector<pair<int, int>> a(n);
    map<int, int> line_mp;
    for(int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
        if (a[i].second < a[i].first) continue;
        auto [x, y] = a[i];
        line_mp[x]++;
        line_mp[y + 1]--;
    }

    vector<int> line(m + 1);
    int active = 0, total = 0, rem = 0;
    for(int i = 1; i <= m; ++i) {
        if (line_mp.count(i))
            active += line_mp[i];
        line[i] = active;
    }


    for(auto &l : line) {
        cout << l << " ";
    }
    cout << "\n";

    // COUNT NUMBER OF PAIRS
    
 
 
    return 0;
}
