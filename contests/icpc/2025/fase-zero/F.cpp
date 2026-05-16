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

        int n;
        cin >> n;
        vector<pair<int, int>> m(n);
        multiset<int> xs;
        multiset<int> ys;

        for(int i = 0; i < n; ++i) {
            cin >> m[i].first >> m[i].second;
            xs.insert(m[i].first);
            ys.insert(m[i].second);
        }


        int coins = (*xs.rbegin() - *xs.begin() + 1) * (*ys.rbegin() - *ys.begin() + 1);

        if (n == 1) {
            cout << 1 << "\n";
            continue;
        }
        // try to improve transfering one
        for(auto &[x, y] : m) {
            //if i remove this guy
            xs.erase(xs.find(x));
            ys.erase(ys.find(y));
            int new_coins = (*xs.rbegin() - *xs.begin() + 1) * (*ys.rbegin() - *ys.begin() + 1);
            if (new_coins < n) {
                new_coins += min((*xs.rbegin() - *xs.begin() + 1), (*ys.rbegin() - *ys.begin() + 1));
            }
            coins = min(coins, new_coins);
            xs.insert(x);
            ys.insert(y);
        }
        
        cout << coins << "\n";

    }
    
    return 0;
}
