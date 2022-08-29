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
 
int main() { 
    FASTIO;
    int t;
    cin >> t;
    while (t--) {
        int s;
        cin >> s;
        string ans;

        if(s < 10) {
            cout << s << "\n";
        }
        else {
            int limit = 9;
            while(s) {
                if(limit > s) {
                    ans += '0' + s;
                    s = 0;
                }
                else {
                    s -= limit;
                    ans += '0' + limit;
                }
                limit--;
            }
            reverse(ans.begin(), ans.end());
            cout << ans << "\n";
        }
    }
    
    return 0; 
}
