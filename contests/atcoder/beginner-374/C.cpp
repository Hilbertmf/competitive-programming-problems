#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (long long)1e18
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

int ans = INF;

void backtrack(int groupA, int groupB, int pos, int n, vector<int>& arr) {
    if (pos >= n) {
        ans = min(ans, max(groupA, groupB));
        return;
    }

    groupA += arr[pos];
    backtrack(groupA, groupB, pos+1, n, arr);
    groupA -= arr[pos];
    groupB += arr[pos];
    backtrack(groupA, groupB, pos+1, n, arr);
}

int32_t main() {
    FASTIO;

    int n;
    cin >> n;
    vector<int> k(n);
    for(int i = 0; i < n; ++i) cin >> k[i];
    
    backtrack(0, 0, 0, n, k);

    cout << ans << "\n";

    return 0;
}
