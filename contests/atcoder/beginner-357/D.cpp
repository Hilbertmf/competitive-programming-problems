#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 998244353;

int mod(string num, int a) {
    int res = 0;
 
    for (int i = 0; i < num.length(); i++)
        res = (res * 10 + num[i] - '0') % a;
 
    return res;
}

int32_t main() {
    FASTIO;
    
    int n;
    cin >> n;

    string v;
    string v1;
    string s = to_string(n);
    for(int i = 0; i < n; ++i) {
        v += s;
    }
    
    for(int i = 0; i < n / 2; ++i) {
        v1 += s;
    }

    DEBUG(v);
    DEBUG(v1);

    int rem = mod(v, MOD);
    int rem1 = mod(v1, MOD);

    cout << rem << "\n";

    DEBUG(rem);
    DEBUG(rem1);

    return 0;
}
