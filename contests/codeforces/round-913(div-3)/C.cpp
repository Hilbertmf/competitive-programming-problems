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
        string s;
        cin >> s;

        map<char, int> count;
        int max_n = 0;

        for(char c : s) {
            count[c]++;
            max_n = max(max_n, count[c]);
        }

        if(n % 2 == 0) {
            cout << max(2*max_n - n, 0ll) << "\n";
        }
        else {
            cout << max(2*max_n - n, 1ll) << "\n";
        }

    }
    
    return 0;
}
