// https://codeforces.com/contest/1993/problem/C
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

        int n, k, start, end, mul;
        cin >> n >> k;
        vector<int> times(n);
        for(int i = 0; i < n; ++i) cin >> times[i];


        bool pos = true;
        int MAX = *max_element(times.begin(), times.end());
        int max_end = MAX + k - 1;
        vector<pair<int, int>> intervals;
        intervals.push_back({MAX, max_end});

        for(auto &time : times) {
            if (time == MAX) continue;
            if (MAX > time + k - 1) {
                mul = floor((MAX - time) / (double)k);
                if (mul % 2 != 0) mul++;
            }
            else {
                mul = 0;
            }

            start = mul * k + time;
            end = start + k - 1;
            intervals.push_back({start, end});
        }

        if(pos) {
            sort(intervals.begin(), intervals.end());
            int max_start = 0;

            for(auto &[st, en] : intervals)
                max_start = max(max_start, st);

            pos = true;
            for(auto &[st, end] : intervals) {
                if (max_start > end) {
                    pos = false;
                    break;
                }
            }
            if(pos) {                
                cout << max_start << "\n";
            }
            else {
                cout << -1 << "\n";
            }
        }
        else {
            cout << -1 << "\n";
        }
    }
    
    return 0;
}
