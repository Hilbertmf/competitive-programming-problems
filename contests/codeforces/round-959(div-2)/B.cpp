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
    
    while(t--) {

        int n;
        cin >> n;
        DEBUG(n);
        bool bobWins = true;
        vector<int> a(n);
        vector<int> b(n);
        vector<char> deleted(n + 1, false);
        map<int, int> num_to_idx;
        for(int i = 0; i < n; ++i) cin >> a[i];
        for(int i = 0; i < n; ++i) cin >> b[i];


        int l = 0, r = n - 1;
        while (l < r) {
            // 2 equalities
            if ((a[l] == b[l] && a[r] == b[r]) ||
                (a[l] == b[r] && a[r] == b[l])) {
                if (a[l] != b[l])
                    swap(b[l], b[r]);
                l++;
                deleted[b[l]] = true;
            }
            else {
                DEBUG(n);
                
                if (deleted[a[l]] || deleted[a[r]]) {
                    bobWins = false;
                    break;
                }

                deleted[b[l]] = true;
                ++l;
            }
        }

        DEBUG(n);
                
        if(bobWins) {
            cout << "Bob\n";
        }
        else {
            cout << "Alice\n";
        }
    }
    
    return 0;
}