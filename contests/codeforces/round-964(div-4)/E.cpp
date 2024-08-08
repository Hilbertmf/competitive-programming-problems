// https://codeforces.com/contest/1999/problem/E
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

int logBaseB(unsigned int n, unsigned int b) {
    int res = 0;
    if (n == 0) return 0;
    if (b == 1) return 0;
    while (n > 1) {
        res++;
        n = (n + b - 1) / b;
    }
    return res;
}

int32_t main() {
    FASTIO;
    int t;
    cin >> t;

    vector<int> powers3;
    powers3.push_back(1);
    while (powers3.back() <= 200000) {
        powers3.push_back({powers3.back() * 3});
    }
    
    while(t--){

        int l, r;
        cin >> l >> r;
        int op = 0;

        int cur = l;
        while (cur > 0) {
            cur /= 3;
            op += 2;
        }
                
        int i = l + 1;
        int curLog = logBaseB(l + 2, 3);

        for (int i = l + 1; i <= r; ) {
            auto it = upper_bound(powers3.begin(), powers3.end(), i);
            int nextPower = (it != powers3.end()) ? *it : r + 1;
            int end = min(r, nextPower - 1);
            int count = end - i + 1;
            op += curLog * count;
            i = end + 1;
            curLog++;
        }

        cout << op << "\n";
    }
    
    return 0;
}
