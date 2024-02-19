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
        vector<char> path(n);
        for(int i = 0; i < n; ++i) {
            cin >> path[i];
        }

        int count = 0;
        int i = 1;
        while (i < n && !(path[i - 1] == '*' && path[i] == '*')) {
            count += path[i] == '@';
            i++;
        }

        cout << count << "\n";

    }
    
    return 0;
}
