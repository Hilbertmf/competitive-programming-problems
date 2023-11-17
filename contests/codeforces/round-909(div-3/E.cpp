// https://codeforces.com/contest/1899/problem/E
// accepted
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
    int t;
    cin >> t;


    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        int min_ = LONGINF;
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
            min_ = min(min_, a[i]);
        }

        int idx = 0;
        while(a[idx] != min_) idx++;
        int ans = idx;

        for(int i = idx; i < n - 1; ++i) {
            // if not sorted after min, impossible
            if(a[i] > a[i+1]) {
                ans = -1;
                break;
            }
        }

        cout << ans << "\n";

    }

    return 0;
}