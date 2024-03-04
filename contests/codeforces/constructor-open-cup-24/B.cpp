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

        int n, m;
        cin >> n >> m;
        vector<int> a(n + 1);
        vector<int> b(m);
        vector<int> ans;

        for(int i = 0; i < m; ++i) {
            cin >> b[i];
        }
        for(int i = 1; i <= n; ++i) {
            a[i] = i;
        }


        int ptr_a = n, ptr_b = m - 1;
        while (ptr_a > 0) {
            if (ptr_a > 0 && (ptr_b < 0 ||
                a[ptr_a] > b[ptr_b])) {
                ans.push_back(a[ptr_a]);
                ptr_a--;
            }

            else if (ptr_a > 0 && ptr_b >= 0 &&
            a[ptr_a] == b[ptr_b]) {
                ptr_a--;
                ptr_b--;
            }
        }

        for(auto &num : ans) {
            cout << num << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
