#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

int getDist(pair<int, int>& p1, pair<int, int>& p2) {
    int x =  abs(p1.first - p2.first);
    int y =  abs(p1.second - p2.second);
    return x * x + y * y;
}

int32_t main() {
    FASTIO;
    int t;
    cin >> t;
    
    while(t--){

        int n;
        cin >> n;
        vector<pair<int, int>> points(n);
        for(int i = 0; i < n; ++i) {
            cin >> points[i].first >> points[i].second;
        }
        pair<int, int> start, end;
        cin >> start.first >> start.second >> end.first >> end.second;

        int dist = getDist(start, end);
        bool possible = true;

        for(int i = 0; i < n && possible; ++i) {
            if (dist >= getDist(points[i], end))
                possible = false;
        }

        if(possible) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    
    return 0;
}
