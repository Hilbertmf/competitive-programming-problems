// AC
// https://codeforces.com/gym/105327/problem/L
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

    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> bits(33);
    for(auto &num : a) {
        cin >> num;
        int cur = num;
        for(int i = 0; i < 33; ++i, cur >>= 1) {
            if (cur & 1)
                bits[i]++;
        }
    }

    for(auto &num : a) {
        int cur = 0;
        for(int i = 0; i < 32; ++i) {
            if (bits[i] > 0) {
                bits[i]--;
                cur += (1 << i);
            }
        }
        cout << cur << " ";
    }
    cout << "\n";
    

    return 0;
}
