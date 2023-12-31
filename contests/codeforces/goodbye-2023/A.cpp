// https://codeforces.com/contest/1916/problem/A
// accepted
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
        vector<int> b(n);
        for(int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        int prod = 1;

        for(int i = 0; i < n; ++i) {
            prod *= b[i];
        }

        bool possible = 2023 % prod == 0;

        if(!possible) {
            cout << "NO" << "\n";
        }
        else {            
            
            cout << "YES" << "\n";
            int d = 2023 / prod;
            cout << d;
            k--;
            while (k--) {
                cout << " ";
                cout << 1;
            }
            cout << "\n";
            
        }
    }
    
    return 0;
}
