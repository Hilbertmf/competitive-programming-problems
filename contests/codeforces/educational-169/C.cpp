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
        vector<int> a(n);
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        int A = 0, B = 0;

        for(int i = n - 1; i >= 1; i -= 2) {
            int diff = min(k, a[i] - a[i - 1]);
            a[i - 1] += diff;
            k -= diff;
        }

        int i;
        for(i = n - 1; i >= 1; i -= 2) {
            A += a[i];
            B += a[i - 1];
        }
        if (i == 0) A += a[i];
        cout << A - B << "\n";
    }
    
    return 0;
}