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
    for(int i = 0; i < n; ++i) cin >> a[i];
    
    vector<int> sorted_a(a.begin(), a.end());
    sort(sorted_a.begin(), sorted_a.end());
    vector<int> prefix(n);
    prefix[0] = sorted_a[0];
    for(int i = 1; i < n; ++i) {
        prefix[i] = sorted_a[i] + prefix[i - 1];
    }

    for(int i = 0; i < n; ++i) {
        int pos = upper_bound(sorted_a.begin(), sorted_a.end(), a[i]) - sorted_a.begin();

        cout << prefix.back() - prefix[pos - 1] << " ";
    }


    return 0;
}
