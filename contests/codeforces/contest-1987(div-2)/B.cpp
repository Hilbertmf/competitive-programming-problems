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
        for(int i = 0; i < n; ++i) cin >> a[i];
        
        int coins = 0;
        map<int, int> count;
        int sum = 0;

        for(int i = 1; i < n; ++i) {
            if (a[i] < a[i - 1]) {
                count[a[i - 1] - a[i]]++;
                a[i] = a[i - 1];
                sum++;
            }
        }

        int prev = -1;
        for(auto &[k, v] : count) {
            int diff = k;
            if (prev != -1)
                diff -= prev;
            coins += (diff) * (sum + 1);
            sum -= v;
            prev = k;
        }

        cout << coins << "\n";
    }
    
    return 0;
}
