// https://codeforces.com/contest/2020/problem/A
// AC
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
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
        vector<int> powers;
        int cur = 1;
        while (true) {
            powers.push_back(cur);
            cur *= k;

            if (cur > n || k == 1) break;
        }

        int op = 0;
        for(int i = powers.size() - 1; i >= 0; --i) {
            if (powers[i] <= n) {
                op += n / powers[i];
                n = n % powers[i];
            }
            if (n == 0) break;
        }

        cout << op << "\n";
    }
    
    return 0;
}
