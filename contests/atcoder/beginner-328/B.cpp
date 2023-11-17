// https://atcoder.jp/contests/abc328/tasks/abc328_b
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
    int n;
    cin >> n;
    int ans = 0;

    for(int i = 1; i <= n; ++i) {
        int days;
        cin >> days;
        string str_i = to_string(i);
        set<char> i_set(str_i.begin(), str_i.end());

        if(i_set.size() > 1) continue;

        for(int j = 1; j <= days; ++j) {
            string str_j = to_string(j);
            set<char> j_set(str_j.begin(), str_j.end());
            bool repdigit = j_set.size() == 1 && j_set == i_set;

            if(repdigit) 
                ans++;
            
        }
    }

    cout << ans << "\n";

    return 0; 
}
