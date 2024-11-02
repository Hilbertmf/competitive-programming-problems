#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define INF_DOUBLE numeric_limits<long double>::max()
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

bool disjoint(pair<long double, long double>& p1, pair<long double, long double>& p2) {
    return p2.first > p1.second;
}

int32_t main() {
    FASTIO;
    int t, tcase = 1;
    cin >> t;

    
    while(t--){

        int n;
        cin >> n;
        vector<pair<int, int>> times(n);
        for(int i = 0; i < n; ++i) {
            cin >> times[i].first >> times[i].second;
        }

        bool possible = true;
        long double dist = 0;
        vector<pair<long double, long double>> speed_intervals;
        for(int i = 0; i < n; ++i) {
            dist = i + 1;
            long double v1 = INF_DOUBLE, v2 = INF_DOUBLE;
            if (times[i].second > 0)
                v1 = dist / (long double)times[i].second;
            if (times[i].first > 0)
                v2 = dist / (long double)times[i].first;

            pair<long double, long double> p = {min(v1, v2), max(v2, v1)};
            speed_intervals.push_back(p);

        }

        sort(speed_intervals.begin(), speed_intervals.end());
        pair<long double, long double> merged_interval = speed_intervals[0];
            
        for(int i = 1; i < n && possible; ++i) {            
            auto cur = speed_intervals[i];
            if (disjoint(merged_interval, cur))
                possible = false;
            
            merged_interval.first = max(merged_interval.first, cur.first);
            merged_interval.second = min(merged_interval.second, cur.second);
        }

        cout << "Case #" << tcase << ": ";
        if(possible) {
            cout << fixed << setprecision(7);
            cout << merged_interval.first << "\n";
        }
        else {
            cout << "-1\n";
        }
        tcase++;
    }
    
    return 0;
}
