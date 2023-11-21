#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (int)1e9
#define LONGINF (long long)1e18
#define MEM(arr, val) memset(arr, (val), sizeof(arr))
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

        int countB = 0;
        for(auto &c : s) {
            if(c == 'B') countB++;
        }

        if(k == countB) {
            cout << 0 << "\n";
        }
        else {
            cout << "1\n";
            int diff = abs(k - countB);

            if(k > countB) {

                int As = 0;
                int i;
                for(i = 0; i <  n; ++i) {
                    if(s[i] == 'A') As++;
                    if(As == diff)
                        break;
                }
                cout << i+1 << " B" << "\n";
            }
            else {

                int Bs = 0;
                int i;
                for(i = 0; i <  n; ++i) {
                    if(s[i] == 'B') Bs++;
                    if(Bs == diff)
                        break;
                }
                cout << i+1 << " A" << "\n";
            }
            
        }
        


    }
    
    return 0;
}
