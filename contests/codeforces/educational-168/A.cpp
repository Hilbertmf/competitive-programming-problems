#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// #define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

int32_t main() {
    FASTIO;
    int t;
    cin >> t;
    
    while(t--){

        


    }
    
    return 0;
}

class MyCalendarTwo {
public:
    multiset<pair<int, int>> intervals;
    MyCalendarTwo() {
        intervals = multiset<pair<int, int>>();
    }

    bool intersect(pair<int, int> p1, pair<int, int> p2) {
        return p1.second > p2.first;
    }
    
    bool book(int start, int end) {
        pair<int, int> p = {start, end};
        if (intervals.size() < 3) {
            intervals.insert(p);
            return true;
        }
        
        intervals.insert(p);
        
        for(auto it = intervals.begin(); it != intervals.end(); ++it) {
            auto nxt = next(it);
            auto nxt_nxt = next(nxt);

            if (intersect(*it, *nxt) && intersect(*it, *nxt_nxt)) {
                intervals.erase(intervals.find(p));
                return false;
            }

            if (next(nxt_nxt) == intervals.end()) break;
        }
        return true;
    }
};
