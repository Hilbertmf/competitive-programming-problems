// acc
// https://codeforces.com/contest/1985/problem/F
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

        int h, n;
        cin >> h >> n;

        priority_queue<vector<int>> heap;
        int time = 0;
        vector<pair<int, int>> dmg_and_cooldonw(n);
        for(int i = 0; i < n; ++i) 
            cin >> dmg_and_cooldonw[i].first;
        for(int i = 0; i < n; ++i)
            cin >> dmg_and_cooldonw[i].second;

        for(int i = 0; i < n; ++i) {
            int dmg = dmg_and_cooldonw[i].first;
            int c = dmg_and_cooldonw[i].second;
            h -= dmg;
            heap.push({-c, dmg, -c});
        }

        while (h > 0) {
            int insert_time = -heap.top()[0];
            int dmg = heap.top()[1];
            int c = -heap.top()[2];
            heap.pop();

            h -= dmg;
            time = insert_time;
            heap.push({-(time + c), dmg, -c});

        }

        cout << time + 1 << "\n";
    }
    
    return 0;
}
