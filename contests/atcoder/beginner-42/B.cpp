#include <bits/stdc++.h> 
using namespace std; 
#define DEBUG(x) cout << #x << " >>>> " << x << endl 
#define MID(l, r) (l + (r - l) / 2) 
#define CEILDIVISION(x, y) ((x + y - 1) / y) 
#define INF (int)1e9 
#define LONGINF (long long)1e18 
#define MEM(arr, val) memset(arr, (val), sizeof(arr)) 
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
#define int long long 
const int MOD = 1e9 + 7; // 10^9 + 7 

int32_t main() { 
    FASTIO;
    int n, l;
    cin >> n >> l;

    vector<string> s(n);
    string sm;
    for(int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    sort(s.begin(), s.end());
    string ans;

    for(auto &str : s) {
        ans += str;
    }

    cout << ans << "\n";

    return 0; 
}
