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
        vector<char> s {'#', '.'};

        int row = 0;
        int row_aux = 0;
        for(int i = 0; i < 2*n; ++i) {
            int line = 0;
            row_aux %= 4;
            if (row_aux < 2)
                row = 0;
            else
                row = 1;
                
            for(int j = 0; j < 2*n; ++j) {
                line %= 4;
                if (line < 2)
                    cout << s[row^0];
                else
                    cout << s[row^1];
                line++;
            }
            cout << "\n";

            row++;
            row_aux++;
        }

    }
    
    return 0;
}
