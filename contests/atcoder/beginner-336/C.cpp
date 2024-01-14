#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

int f(int n, map<int, int>& mp) {
    
    int res = 0;
    while (n >= 5) {

        auto it = mp.lower_bound(n);
        if(it->first > n)
            it = prev(it);
        n -= it->first;
        res += it->second;

    }
    
    if(n >= 0 && n < 5) {
        res += n * 2;
    }

    return res;    
}

int32_t main() {
    FASTIO;

    int n;
    cin >> n;
    n--;
    vector<int> vec(18);
    map<int, int> mp;
    mp.insert({0, 0});
    int base = 5, res = 20;
    mp.insert({base, res});
    for(int i = 1; i < 18; ++i) {
        base *= 5;
        res *= 10;
        mp.insert({base, res});
    }

    cout << f(n, mp) << "\n";

    return 0;
}
