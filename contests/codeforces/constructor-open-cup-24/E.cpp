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
        vector<int> seconds(n);
        for(auto &s : seconds) cin >> s;
        
        vector<int> attack_times_elems(n);
        int attack = 1, elems = n;
        int dmg = 0;
        for(int i = 0; i < n; ++i) {
            
            attack_times_elems[i] = attack * elems;
            attack++;
            elems--;
        }
        sort(attack_times_elems.rbegin(), attack_times_elems.rend());
        sort(seconds.begin(), seconds.end());
        for(int i = 0; i < n; ++i) {
            dmg += attack_times_elems[i] * seconds[i];
        }

        cout << dmg << "\n";
    }
    
    return 0;
}
