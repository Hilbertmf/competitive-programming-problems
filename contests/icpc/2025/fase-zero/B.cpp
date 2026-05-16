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

        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        int ones = 0, zeros = 0;
        for(auto &c : s) {
            if (c == '1') ones++;
            else zeros++;
        }
        int max_ = ones/2 + zeros/2;
        int min_ = abs(zeros - ones) / 2;
        
        bool possible = k <= max_ && k >= min_ && (k % 2 == max_ % 2);
        
        if(possible) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    
    return 0;
}
