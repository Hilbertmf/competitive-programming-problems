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
        int start = INF, end = n - 1;
        int dist = 0;

        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == 'B') {
                start = i;
                break;
            }
        }
        
            
        
        for(int i = n - 1; i >= 0; --i) {
            if(s[i] == 'B') {
                end = i;
                break;
            }
        }

        if(start == INF) {
            cout << 0 << "\n";
        }
        else {
            cout << end - start + 1 << "\n";
        }
    }
    
    return 0;
}
