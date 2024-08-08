// https://codeforces.com/contest/1999/problem/C
#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int MOD = 1e9 + 7; // 10^9 + 7

int32_t main() {
    FASTIO;
    int t;
    cin >> t;
    
    while(t--){

        int n, s, m;
        cin >> n >> s >> m;

        vector<pair<int, int>> intervals(n);
        for(int i = 0; i < n; ++i) {
            cin >> intervals[i].first >> intervals[i].second;
        }

        bool pos = false;

        sort(intervals.begin(), intervals.end());

        if ((intervals[0].first > 0 && intervals[0].first >= s) ||
        m - intervals.back().second >= s) {
            pos = true;
        }

        for(int i = 1; i < n && !pos; ++i) {
            if (intervals[i].first - intervals[i - 1].second >= s) {
                pos = true; break;
            }
        }

        if(pos) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";            
        }
    }
    
    return 0;
}
