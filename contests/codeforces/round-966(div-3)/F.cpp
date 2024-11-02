// TODO
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

        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> rec(n);
        priority_queue<vector<int>> min_heap;
        for(int i = 0; i < n; ++i) {
            cin >> rec[i].first >> rec[i].second;
            int a = min(rec[i].first, rec[i].second);
            int b = max(rec[i].first, rec[i].second);
            min_heap.push({-a, -b});
        }

        int points = 0, op = 0, best = INF;
        while (points < k && !min_heap.empty()) {
            int x = -min_heap.top()[0];
            int y = -min_heap.top()[1];
            min_heap.pop();

            vector<int> coord = {x, y};
            sort(coord.begin(), coord.end());
            if (coord[0] > 0) {
                op += coord[0];
                coord[1]--;
                points++;
                sort(coord.begin(), coord.end());
                if (coord[0] > 0)
                    min_heap.push({-coord[0], -coord[1]});
            }

            if (points == k) break;
        }

        if (points != k)
            cout << "-1\n";
        else
            cout << op << "\n";
    }
    
    return 0;
}
