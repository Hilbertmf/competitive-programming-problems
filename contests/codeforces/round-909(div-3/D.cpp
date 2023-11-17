// https://codeforces.com/contest/1899/problem/D
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

int C2(int n) {
    return (n * (n-1)) / 2;
}

int32_t main() { 
    FASTIO;
    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;
        vector<int> a(n);
        map<int, int> count;
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
            count[a[i]]++;
        }

        int ans = 0;

        for(auto &[key, val] : count) {
            if(val == 1) continue;
            ans += C2(val);
        }

        if(count.find(1) != count.end()&& count.find(2) != count.end()) {
            ans += count[2] * count[1];
        }

        cout << ans << "\n";
    }

    return 0; 
}
