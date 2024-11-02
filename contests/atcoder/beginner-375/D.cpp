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

    string s;
    cin >> s;

    int n = s.size();
    map<char, set<int>> indices;
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        indices[s[i]].insert(i);
    }
    
    for(char c = 'A'; c <= 'Z'; ++c) {
        if (!indices.count(c) || indices[c].size() <= 1) continue;

        vector<int> positions(indices[c].begin(), indices[c].end());
        int sz = positions.size();
        vector<int> prefix(sz);
        prefix[0] = positions[0];

        for(int i = 1; i < sz; ++i) {
            prefix[i] = positions[i] + prefix[i - 1];
        }
        
        for(int i = 1; i < sz; ++i) {
            int last = i;
            if (positions[i] - positions[i - 1] == 1)
                last = i - 1;            
            int cur = positions[i] * last;
            if (last - 1 >= 0) cur -= prefix[last - 1] + (last);
            ans += cur;
        }

    }

    cout << ans << "\n";

    return 0;
}
