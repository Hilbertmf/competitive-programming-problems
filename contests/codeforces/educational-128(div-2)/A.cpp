// accepted
// https://codeforces.com/contest/1680/problem/A
#include <bits/stdc++.h> 
using namespace std; 
#define DEBUG(x) cout << #x << " >>>> " << x << endl 
#define MID(l, r) (l + (r - l) / 2) 
#define CEILDIVISION(x, y) ((x + y - 1) / y) 
#define INF (int)1e9 
#define LONGINF (long long)1e18 
#define MEM(arr, val) memset(arr, (val), sizeof(arr)) 
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
const int MOD = 1000000007; // 10^9 - 7 
 
int main() { 
    FASTIO;
    int t;
    cin >> t;

    while (t--) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        int max1 = max(l1, r1);
        int max2 = max(l2, r2);
        int min1 = min(l1, r1);
        int min2 = min(l2, r2);
        int ans;
        if(max1 < min2 || max2 < min1) {
            ans = min1 + min2;
        }
        else {
            ans = max(min1, min2);
        }

        cout << ans << endl;
    }	
    
    return 0; 
}
