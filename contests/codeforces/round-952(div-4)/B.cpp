// acc
// https://codeforces.com/contest/1985/problem/B
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

        int x = 2;
        int ans = x;
        int best = 0;
        for(int x = 2; x <= n; ++x) {
            int sum = 0;
            for(int k = 1; k * x <= n; ++k) {
                sum += k * x;
            }

            if (sum > best) {
                ans = x;
                best = sum;
            }
        }


        cout << ans << "\n";
    }
    
    return 0;
}

/*
100 * 100 * 100
*/