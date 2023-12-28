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
        vector<int> a(n);
        int prod = 1;
        for(auto &num : a) {
            cin >> num;
        }

        int min_idx = min_element(a.begin(), a.end()) - a.begin();
        int min_elem = a[min_idx];

        for(int i = 0; i < n; ++i) {
            if(i == min_idx) {
                prod *= a[i] + 1;
            }
            else {
                prod *= a[i];
            }
        }
        

        cout << prod << "\n";
    }
    
    return 0;
}
