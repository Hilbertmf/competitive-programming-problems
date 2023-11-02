// https://codeforces.com/contest/1891/problem/A
// accepted
#include <bits/stdc++.h> 
using namespace std; 
#define DEBUG(x) cout << #x << " >>>> " << x << endl 
#define MID(l, r) (l + (r - l) / 2) 
#define CEILDIVISION(x, y) ((x + y - 1) / y) 
#define INF (int)1e9 
#define LONGINF (long long)1e18 
#define MEM(arr, val) memset(arr, (val), sizeof(arr)) 
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
const int MOD = 1000000007; // 10^9 - 7 
#define int long long
 
int32_t main() { 
    FASTIO;
    vector<int> powers_2_v(37);
    powers_2_v[0] = 1;
    for(int i = 1; i < powers_2_v.size(); ++i) {
        powers_2_v[i] = 2 * powers_2_v[i - 1];
    }
    set<int> powers_2(powers_2_v.begin(), powers_2_v.end());

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        bool possible = true;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int greater_power_2 = *prev(powers_2.upper_bound(n));

        for(int i = 3; i < n; ++i) {
            
            if(a[i - 1] > a[i] && (powers_2.find(i) == powers_2.end() ||
            i > greater_power_2)) {
                possible = false;
                break;
            }
        }


        if(possible) {
            cout << "YES" << "\n";
        }
        else {
            cout << "NO" << "\n";
        }

    }
    
    return 0; 
}
