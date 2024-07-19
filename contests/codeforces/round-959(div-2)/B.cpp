// https://codeforces.com/contest/1994/problem/B
// ac
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
        string s, t;
        cin >> s >> t;
        bool equal = s == t;
        bool possible = true;
        int last1 = -1;

        for(int i = 0; i < n && !equal && possible; ++i) {
            if (s[i] != t[i] && last1 == -1 && s[i] == '0') {
                possible = false;
            }
            if (s[i] == '1')
                last1 = i;
        }

        if(s[0] == '1' || possible || equal) {
            cout << "YES" << "\n";
        }
        else {
            cout << "NO" << "\n";
        }
    }    
    return 0;
}
