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
        char grid[n][4];
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < 4; ++j) {
                cin >> grid[i][j];
            }
        }


        vector<int> ans;
        for(int i = n - 1; i >= 0; --i) {
            int j;
            for(j = 0; j < 4; ++j) {
                if (grid[i][j] == '#') break;
            }
            ans.push_back(j + 1);
        }

        for(int i = 0; i < ans.size(); ++i) {
            if (i != 0) cout << " ";
            cout << ans[i];
        }
        cout << "\n";
    }
    
    return 0;
}
