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
    int curr = 0, num, start = 0;
    int min_curr = INF;

    for(int i = 0; i < n; ++i) {
        cin >> num;
        curr += num;
        min_curr = min(min_curr, curr);
    }

    if(min_curr < 0)
        start = -min_curr;
    
    cout << curr + start << "\n";

    return 0;
}
