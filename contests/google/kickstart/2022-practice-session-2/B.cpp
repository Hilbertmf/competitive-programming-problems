// accepted
// https://codingcompetitions.withgoogle.com/kickstart/round/00000000008f4a94/0000000000b5496b
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
    int tests;
    cin >> tests;
    for(int t = 0; t < tests; ++t) {
        int l, r;
        cin >> l >> r;
        long long numSets = min(l, r);

        long long ans = (numSets * (numSets + 1)) / 2;

        cout << "Case #" << t+1 << ": " << ans << "\n";
    }
    return 0; 
}
